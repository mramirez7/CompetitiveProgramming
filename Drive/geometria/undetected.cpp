//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
};

struct circle{
    point center;
    int r;
    int left_limit, right_limit;
};

double dist(point a, point b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool areIntersect(circle c1, circle c2){
    if ((c1.r + c2.r)*(c1.r + c2.r) >= dist(c1.center, c2.center)) return true;
    return false;
}

vector <circle> circles;
int rep[200];

int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}

int main() {
    int  n, rep1, rep2, ans = 0;
    cin >> n;
    for (int k = 0; k < n; ++k) rep[k] = k;
    circles.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].center.x >> circles[i].center.y >> circles[i].r;
        circles[i].left_limit = circles[i].center.x - circles[i].r;
        circles[i].right_limit = circles[i].center.x + circles[i].r;
    }
    for (int j = 0; j < n; ++j) {
        rep1 = find(j);
        for (int i = 0; i < j; ++i) {
            rep2 = find(i);
            if (areIntersect(circles[j], circles[i]) && rep1 != rep2){
                union_(i, rep1);
                circles[rep1].left_limit = min(circles[rep2].left_limit, circles[rep1].left_limit);
                circles[rep1].right_limit = max(circles[rep2].right_limit, circles[rep1].right_limit);
            }
        }
        if (circles[rep1].left_limit <= 0 && circles[rep1].right_limit >= 200) break;
        else ans++;
    }
    cout << ans << "\n";
}