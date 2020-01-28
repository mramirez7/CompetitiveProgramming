//WA veo si todos los puntos están a menor distancia o igual al diametro, no encuentro contraejemplos
#include <bits/stdc++.h>
using namespace std;

double EPS = 1E-12;

struct point{
    double x, y;
};

double dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

vector <point> points;

int main() {
    int n, flag;
    double x, y, d;
    while (cin >> n){
        if (!n) break;
        flag = 1;
        points.clear();
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            points.push_back({x,y});
        }
        cin >> d;
        d *= 2.0;
        d *= d;
        for (int j = 0; j < n; ++j) {
            for (int i = j+1; i < n; ++i) {
                if (dist(points[j],points[i]) - d > EPS){
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }
}