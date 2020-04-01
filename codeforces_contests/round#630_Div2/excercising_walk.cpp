#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int main(){
    int t, ans, x, y, x1, y1, x2, y2, a, b,c,d;
    cin >> t;
    while (t--){
        ans = 1;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        int hor = b - a;
        int ver = d - c;
        if (hor == 0 && a != 0){
            if (x1 == x && x2 == x)
                ans = 0;
        }
        if (ver == 0 && d != 0){
            if (y1 == y && y2 == y)
                ans = 0;
        }
        if (hor + x < x1 || hor + x > x2 || ver + y < y1 || ver + y > y2)
            ans = 0;
        if (ans) cout << "Yes\n";
        else cout << "No\n";
    }
}