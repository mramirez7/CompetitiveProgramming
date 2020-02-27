#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    while (cin >> n){
         if (!n) break;
         multiset<int> ms;
         long long ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> p;
            for (int j = 0; j < p; ++j) {
                cin >> m;
                ms.insert(m);
            }
            auto it = ms.begin();
            ans -= *it;
            ms.erase(it);
            it = ms.end();
            it--;
            ans += *it;
            ms.erase(it);
        }
        cout << ans << "\n";
    }
}