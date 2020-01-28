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
    int id_;
    double a, b, c;
    point top, bottom;
};

vector <int> dp;
vector <bool> visited;
vector <segment> segments;
vector <point> points;

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

void print_r(line r){cout << r.a << " " << r.b << " " << r.c << "\n";}

int cascade(segment s){
    point intersection;
    if (visited[s.id_]){
        return dp[s.id_];
    }
    visited[s.id_] = true;
    if (s.bottom.y < EPS){
        areIntersect({0.0,1.0,0.0},{s.a,s.b,s.c}, intersection);
        dp[s.id_] = (int)intersection.x;
        return dp[s.id_];
    }
    int index_seg;
    int max_high = -INT_MAX;
    for (int i = 0; i < segments.size(); ++i) {
        if (i == s.id_) continue;
        if (areIntersect({1.0,0.0,-s.bottom.x}, {segments[i].a,segments[i].b, segments[i].c}, intersection)&& inSegment(intersection, segments[i])){
            if (intersection.y - max_high > -EPS && s.bottom.y - intersection.y> -EPS){
                max_high = intersection.y;
                index_seg = i;
                if (max_high < EPS) {
                    dp[s.id_] = (int)intersection.x;
                    return dp[s.id_];
                }
            }
        }
    }
    dp[s.id_] = cascade(segments[index_seg]);
    return dp[s.id_];
}

int main() {
    int n, l, p, flag;
    double x1, y1, x2, y2;
    point intersection;
    cin >> n;
    while (n--){
        cin >> l;
        segments.clear();
        points.clear();
        dp.clear();
        for (int i = 0; i < l; ++i) {
            cin  >> x1 >> y1 >> x2 >> y2;
            line nl;
            line_generator({x1,y1},{x2,y2}, nl);
            segments.push_back({i,nl.a,nl.b,nl.c});
            if (y1>y2){
                segments[segments.size()-1].top.x = x1;
                segments[segments.size()-1].top.y = y1;
                segments[segments.size()-1].bottom.x = x2;
                segments[segments.size()-1].bottom.y = y2;
            }else{
                segments[segments.size()-1].top.x = x2;
                segments[segments.size()-1].top.y = y2;
                segments[segments.size()-1].bottom.x = x1;
                segments[segments.size()-1].bottom.y = y1;
            }
        }
        segments.push_back({l,0.0,1.0,0.0}); //eje x
        segments[l].top = {(double)INT_MAX, 0.0};
        segments[l].bottom = {-(double)INT_MAX, 0.0};
        dp.reserve(l);
        visited.assign(l, false);
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> x1 >> y1;
            points.push_back({x1, y1});
        }
        int max_high = -INT_MAX;
        int index_seg = 0;
        for (int k = 0; k < l; ++k) {
            flag = 0;
            int max_high = -INT_MAX;
            for (int i = 0; i < segments.size(); ++i) {
                if (areIntersect({1.0,0.0,-points[k].x}, {segments[i].a,segments[i].b, segments[i].c}, intersection)&& inSegment(intersection, segments[i])){
                    if (intersection.y - max_high > -EPS && points[k].y - intersection.y> -EPS){
                        max_high = intersection.y;
                        index_seg = i;
                        if (max_high < EPS) {
                            cout << (int)intersection.x<<"\n";
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (!flag) {
                cascade(segments[index_seg]);
                cout << dp[segments[index_seg].id_]<<"\n";
            }
        }
        if (n) cout << "\n";
    }
}