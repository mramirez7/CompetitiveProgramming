#include <bits/stdc++.h>
using namespace std;

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

bool pointEqual(point p1, point p2){
    if (fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS) return true;
    return false;
}

double producto_punto(point p1, point p2,point p3){
    p1.x -= p3.x;
    p2.x -= p3.x;
    p1.y -= p3.y;
    p2.y -= p3.y;
    return fabs(p1.x*p2.x + p1.y*p2.y);
}


vector <point> pts;

int main(){
    double x1, y1, x2, y2;
    line l1, l2, l3, l4;
    point a, b, c;
    for (int i = 0; i < 4; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        pts.push_back({x1,y1});
        pts.push_back({x2,y2});
        if (i==0) line_generator(pts[2*i], pts[2*i+1], l1);
        if (i==1) line_generator(pts[2*i], pts[2*i+1], l2);
        if (i==2) line_generator(pts[2*i], pts[2*i+1], l3);
        if (i==3) line_generator(pts[2*i], pts[2*i+1], l4);
    }
    if (!((areParallel(l1, l2) && areParallel(l3,l4)) || (areParallel(l1,l3) && areParallel(l4, l2)) || (areParallel(l1,l4)&&areParallel(l2,l3)))){
        cout << "NO\n";
        return 0;
    }
    if (areSame(l1, l2) || areSame(l1,l3) || areSame(l1, l4) || areSame(l2, l3) || areSame(l2, l4) || areSame(l3,l4)){
        cout << "NO\n";
        return 0;
    }
    int have_pair[8] = {0,0,0,0,0,0,0,0};
    for (int j = 0; j < 8; ++j) {
        for (int i = j+1; i < 8; ++i) {
            if (pointEqual(pts[j], pts[i])){
                have_pair[j] = 1;
                have_pair[i] = 1;
            }
        }
    }
    for (int k = 0; k < 8; ++k) {
        if (!have_pair[k]){
            cout << "NO\n";
            return 0;
        }
    }
/*
    if (areParallel(l1, l2)){
        if (pointEqual(pts[0], pts[4])) {
            if (producto_punto(pts[1], pts[5], pts[0]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else if (pointEqual(pts[0], pts[5])){
            if (producto_punto(pts[1], pts[4], pts[0]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else if (pointEqual(pts[1], pts[4])){
            if (producto_punto(pts[0], pts[5], pts[1]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else{
            if (producto_punto(pts[0], pts[4], pts[1]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (areParallel(l1, l3)){
        if (pointEqual(pts[0], pts[2])) {
            if (producto_punto(pts[1], pts[3], pts[0]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else if (pointEqual(pts[0], pts[3])){
            if (producto_punto(pts[1], pts[3], pts[0]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else if (pointEqual(pts[1], pts[2])){
            if (producto_punto(pts[0], pts[3], pts[1]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }else{
            if (producto_punto(pts[0], pts[2], pts[1]) > EPS){
                cout << "NO\n";
                return 0;
            }
        }
    }
*/
    for (int l = 0; l < 4; ++l) {
        if (pts[2*l].x != pts [2*l+1].x && pts[2*l].y != pts [2*l+1].y){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}