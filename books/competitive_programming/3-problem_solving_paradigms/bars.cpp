#include <bits/stdc++.h>
using namespace std;

int bars[20];

int main() {
    int t, n, p, sum_, aux, flag;
    cin >> t;
    while (t--){
        flag = 0;
        cin >> n >> p;
        if (!n) flag = 1;
        for (int i = 0; i < p; ++i) {
            cin >> bars[i];
        }
        for (int j = 1; j < 1<<p; ++j) {
            sum_ = 0;
            for (int i = 0; i < p; ++i) {
                if (j & (1<<i)) sum_ += bars[i];
            }
            if (sum_ == n){
                flag = 1;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}