#include <bits/stdc++.h>
using namespace std;

struct point{
    long long x, y;
};

long long dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

vector <point> points;
vector<vector<long long>> d;

int main() {
    int n;
    long long ans;
    while (cin >> n) {
        if (!n) return 0;
        ans = 0;
        points.clear();
        d.clear();
        points.reserve(n);
        d.assign(n, vector<long long>());
        for (int i = 0; i < n; ++i) {
            d[i].assign(n, 0);
            cin >> points[i].x >> points[i].y;
        }
        for (int j = 0; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                d[j][i] = dist(points[j], points[i]);
                d[i][j] = d[j][i];
            }
        }
        int cont = 1;
        for (int k = 0; k < n; ++k) {
            sort(d[k].begin(), d[k].begin()+n);
            for (int i = 1; i < n; ++i) {
                if (d[k][i-1] != d[k][i]){
                    ans += ((cont*(cont-1))/2);
                    cont = 1;
                } else cont++;
            }
        }
        ans += ((cont*(cont-1))/2);
        cout << ans << "\n";
    }
}
