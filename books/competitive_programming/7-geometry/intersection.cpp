#include <bits/stdc++.h>
using namespace std;

double start_x, start_y, end_x, end_y, lt_x, lt_y, rb_x, rb_y;
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

bool inSegment(point p){
    int max_y = start_y, min_y = end_y;
    if (max_y < min_y) swap(max_y, min_y);
    return (( p.x - start_x > -EPS) && (end_x - p.x > -EPS) && (p.y - min_y > -EPS) && (max_y-p.y>-EPS));
}

void print_r(line r){cout << r.a << " " << r.b << " " << r.c << "\n";}

int main() {
    int n;
    cin >> n;
    point intersect;
    while (n--){
        cin >> start_x >> start_y >> end_x >> end_y >> lt_x >> lt_y >> rb_x >> rb_y;
        if (start_x > end_x){
            swap(start_x, end_x);
            swap(start_y, end_y);
        }if (lt_x > rb_x) swap(lt_x,rb_x);
        if (lt_y < rb_y) swap(lt_y, rb_y);
        line recta, rtop, rbottom, rleft, rright;
        line_generator({start_x, start_y}, {end_x,end_y}, recta);
        line_generator({lt_x, rb_y}, {lt_x,lt_y}, rleft);
        line_generator({rb_x, rb_y}, {rb_x, lt_y}, rright);
        line_generator({lt_x, rb_y}, {rb_x,rb_y}, rbottom);
        line_generator({lt_x, lt_y}, {rb_x,lt_y}, rtop);

        if (areIntersect(recta, rtop, intersect)) {
            if ((intersect.x - lt_x > -EPS) && (rb_x - intersect.x > -EPS) && inSegment(intersect)){
                cout << "T\n";
                continue;
            }
        }if (areIntersect(recta, rbottom, intersect)) {
            if ((intersect.x - lt_x > -EPS) && (rb_x - intersect.x > -EPS)&& inSegment(intersect)){
                cout << "T\n";
                continue;
            }
        }if (areIntersect(recta, rleft, intersect)) {
            if ((intersect.y - rb_y > -EPS)&&(lt_y - intersect.y >-EPS) && inSegment(intersect)){
                cout << "T\n";
                continue;
            }
        }if (areIntersect(recta, rright, intersect)) {
            if ((intersect.y - rb_y > -EPS)&&(lt_y - intersect.y >-EPS)&& inSegment(intersect)){
                cout << "T\n";
                continue;
            }
        }
        if ((start_x-lt_x >= 0) && (rb_x-start_x >= 0) && (start_y - rb_y >= 0)&&(lt_y-start_y>=0)){
            cout << "T\n";
            continue;
        }
        cout << "F\n";
    }
}