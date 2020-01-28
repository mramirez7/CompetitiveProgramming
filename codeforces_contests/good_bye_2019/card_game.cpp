#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k1, k2, max_, winner_1, c;
    cin >> t;
    while (t--){
        max_ = 0;
        winner_1 = 0;
        cin >> n >> k1 >> k2;
        for (int i = 0; i < k1; ++i) {
            cin >> c;
            if (c > max_){
                winner_1 = 1;
                max_ = c;
            }
        }
        for (int j = 0; j < k2; ++j) {
            cin >> c;
            if (c > max_){
                winner_1 = 2;
            }
        }
        if (winner_1 == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}