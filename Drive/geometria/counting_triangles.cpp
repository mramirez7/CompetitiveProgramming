//ACCEPTED
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

bool areParallel(line l1, line l2){
    return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
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

vector <segment> segments;

int main() {
    int n, ans;
    point p1, p2, p3;
    while (cin >> n){
        if (!n) break;
        ans = 0;
        segments.reserve(n);
        for (int i = 0; i < n; ++i) {
            cin >> segments[i].p1.x >> segments[i].p1.y >> segments[i].p2.x >> segments[i].p2.y;
            line_generator(segments[i].p1, segments[i].p2, segments[i].l);
        }
        for (int j = 0; j < n; ++j) {
            for (int i = j+1; i < n; ++i) {
                for (int k = i+1; k < n; ++k) {
                    if (areIntersect(segments[j].l, segments[i].l, p1) && areIntersect(segments[j].l, segments[k].l, p2) && areIntersect(segments[i].l, segments[k].l, p3)){
                        if (inSegment(segments[j], p1) && inSegment(segments[i], p1) && inSegment(segments[j], p2) && inSegment(segments[k], p2) && inSegment(segments[i], p3) && inSegment(segments[k], p3)) ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}