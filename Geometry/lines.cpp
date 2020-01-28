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
    point p1, p2;
    line l;
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

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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

bool inSegment(segment s, point p){
    if (max(s.p1.x, s.p2.x) >= p.x && min(s.p1.x, s.p2.x) <= p.x && max(s.p1.y, s.p2.y) >= p.y && min(s.p1.y, s.p2.y) <= p.y) return true;
    return false;
}

bool counter_clock_wise_comparator(point &p1, point &p2) {
    point a, b;
    a = normalized(p1); b = normalized(p2);
    if ((a.y > EPS || (fabs(a.y) < EPS && a.x > EPS)) && (b.y < -EPS || (fabs(b.y) < EPS && b.x < -EPS))) return true;
    if ((b.y > EPS || (fabs(b.y) < EPS && b.x > EPS)) && (a.y < -EPS || (fabs(a.y) < EPS && a.x < -EPS))) return false;
    if ((a.y > EPS || (fabs(a.y) < EPS && a.x > EPS))) return a.x > a.y;
    else return a.x < a.y;
}

int main() {
}
