#include <bits/stdc++.h>
using namespace std;

double x1, y11 ,x2,y2,x3,y3,x4,y4;
double EPS = 1E-12;

struct point{
    double x, y;
};

struct line{
    double a, b, c;
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

void print_r(line r){cout << r.a << " " << r.b << " " << r.c << "\n";}

int main() {
    int n;
    cout << setprecision(2) << fixed;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT\n";
    while (n--){
        cin >> x1 >> y11 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        line l1, l2;
        point intersection;
        line_generator({x1,y11},{x2,y2},l1);
        line_generator({x3,y3},{x4,y4},l2);
        if (areSame(l1,l2)) cout << "LINE\n";
        else if (areParallel(l1, l2)) cout << "NONE\n";
        else {
            cout << "POINT ";
            areIntersect(l1, l2, intersection);
            cout << intersection.x << " " << intersection.y << "\n";
        }
    }
    cout << "END OF OUTPUT\n";
}