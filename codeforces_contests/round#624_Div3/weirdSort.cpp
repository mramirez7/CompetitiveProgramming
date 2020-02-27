#include <bits/stdc++.h>
using namespace std;

int a[101], pos[101], sorted[101];

int main(){
    int t, n, m, aux, sol;
    cin >> t;
    while (t--){
        cin >> n >> m;
        sol = 1;
        set <int> p;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sorted[i] = a[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> aux;
            p.insert(--aux);
        }
        sort(sorted, sorted+n);
        for (int k = 0; k < n; ++k) pos[k] = -1;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < n; ++i) {
                if (sorted[l] == a[i] && pos[i] == -1) {
                    pos[i] = l;
                    break;
                }
            }
        }
        for (int j1 = 0; j1 < n; ++j1) {
            if (pos[j1] > j1){
                for (int i = j1; i < pos[j1]; ++i) {
                    if (p.find(i) == p.end()){
                        sol = 0;
                        break;
                    }
                }
            }
        }
        if (sol) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}