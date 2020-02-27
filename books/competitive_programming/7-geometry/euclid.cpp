//FAIL
#include <bits/stdc++.h>
using namespace std;

double EPS = 1E-12;

struct point{
    double x, y;
};

struct line{
    double a, b, c;
};

struct segment{
    int id_;
    double a, b, c;
    point top, bottom;
};

void line_generator(point p1, point p2, line &l){
    if (fabs(p1.x-p2.x)<EPS){
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }else {
        l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2){
    return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}

bool areSame(line l1, line l2){
    return areParallel(l1, l2) && (fabs(l1.c-l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b*l2.c)/(l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);//a
    else p.y = -(l2.a*p.x + l2.c);
    return true;
}

bool inSegment(point p, segment s){
    if (s.top.x < s.bottom.x)
        return ((p.x - s.top.x > -EPS) && (s.bottom.x - p.x > -EPS) && (p.y - s.bottom.y > -EPS) && (s.top.y - p.y > -EPS));
    else
        return ((p.x - s.bottom.x > -EPS) && (s.top.x - p.x > -EPS) && (p.y - s.bottom.y > -EPS) && (s.top.y - p.y > -EPS));
}

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double heronForTriangle(point a, point b, point c){
    double semiP = (dist(a,b)+dist(a,c)+dist(b,c))/2;
    return sqrt(semiP*(semiP-dist(a,b))*(semiP-dist(a,c))*(semiP-dist(b,c)));
}

double dot(point a, point b) {
    return a.x*b.x + a.y*b.y;
}

double angle(point a, point o, point b){
    point oa = {a.x-o.x,a.y-o.y};
    point ob = {b.x-o.x,b.y-o.y};
    return acos(dot(oa, ob) / (dist(a, {0.0,0.0}) * dist(b, {0.0,0.0})));
}

double bascara(double a, double b, double c, int flag){ //1 = + ; 2 = -
    double disc = sqrt(b*b - 4*a*c);
    if (flag) return (-b + disc)/(2*a);
    return (-b - disc)/(2*a);
}

int main() {
    cout.precision(3);
    cout << fixed;
    double xa, ya, xb, yb, xc, yc, xd, yd, xe, ye, xf, yf;
    double area_triangulo, altura_parallel, angulo, lado, x_vector, y_vector;
    point a,b,c,d,e,f,g,h;
    line ac;
    while (1){
        cin >> xa>> ya>> xb>> yb>> xc>> yc>> xd>> yd>>xe>> ye>> xf >> yf;
        if (fabs(xa) < EPS && fabs(ya) < EPS && fabs(xb) < EPS && fabs(yb) < EPS && fabs(xc) < EPS && fabs(yc) < EPS && fabs(xd) < EPS && fabs(yd) < EPS && fabs(xe) < EPS && fabs(ye) < EPS && fabs(xf) < EPS && fabs(yf) < EPS) break;
        a = {xa, ya}; b = {xb,yb}; c = {xc, yc}; d = {xd, yd}; e = {xe, ye}; f = {xf, yf};
        area_triangulo = heronForTriangle(e,d,f);
        altura_parallel = area_triangulo/dist(a,b);
        angulo = angle(b,a,c);
        cout << angulo << "\n";
        lado = altura_parallel/sin(angulo);
        line_generator(a,c,ac);
        if (ac.b) {
            if (c.x > a.x || (c.x == a.x && c.y > a.y)) {
                x_vector = bascara(1 + (ac.a * ac.a) / (ac.b * ac.b),
                                   2 * ac.a * ac.c / (ac.b) + 2 * ac.a * a.y / ac.b - 2 * a.x,
                                   a.x * a.x + a.y * a.y + 2 * a.y * ac.c / ac.b + ac.c * ac.c / (ac.b * ac.b), 1);
            } else
                x_vector = bascara(1 + (ac.a * ac.a) / (ac.b * ac.b),
                                   2 * ac.a * ac.c / (ac.b) + 2 * ac.a * a.y / ac.b - 2 * a.x,
                                   a.x * a.x + a.y * a.y + 2 * a.y * ac.c / ac.b + ac.c * ac.c / (ac.b * ac.b), 0);
            y_vector = (-ac.a / ac.b) * x_vector - ac.c / ac.b;
        }else{
            if (c.y > a.y) {
                x_vector = a.x;
                y_vector = a.y + altura_parallel;
            }else{
                x_vector = a.x;
                y_vector = a.y - altura_parallel;
            }
        }
        x_vector -= a.x;
        y_vector -= a.y;
        cout << x_vector << " " << y_vector << "\n";
        cout << x_vector+b.x << " " << y_vector+b.y << " ";
        cout << x_vector+a.x << " " << y_vector+a.y << "\n";
    }
}