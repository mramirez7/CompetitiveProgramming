#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

bool comp(point p1, point p2){
    if (p1.x < p2.x) return true;
    if (p2.x < p1.x) return false;
    if (p1.y < p2.y) return true;
    if (p1.y > p2.y) return false;
}

point points[1000];

int main() {
    int t, n;
    string s;
    cin >> t;
    while (t--){
        s = "";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        sort(points, points + n, comp);
        point last = {0, 0};
        int flag = 1;
        for (int j = 0; j < n; ++j) {
            if (points[j].x < last.x || points[j].y < last.y){
                flag = 0;
                break;
            }
            for (int i = 0; i < points[j].x - last.x; ++i) {
                s += "R";
            }
            for (int i = 0; i < points[j].y - last.y; ++i) {
                s += "U";
            }
            last.x = points[j].x;
            last.y = points[j].y;
        }
        if (!flag) cout <<"NO\n";
        else{
            cout << "YES\n";
            cout << s << "\n";
        }
    }
}