#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, b, h, w, ans;
    int p, w_, max_w;
    while (cin >> n >> b >> h >> w){
        ans = INT_MAX;
        for (int i = 0; i < h; ++i) {
            max_w = 0;
            cin >> p;
            for (int j = 0; j < w; ++j) {
                cin >> w_;
                max_w = max(max_w, w_);
            }
            if (max_w >= n && b >= p*n) ans = min(ans,p*n);
        }
        if (ans == INT_MAX) cout << "stay home\n";
        else cout << ans << "\n";
    }
}
