#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi maxs;

int main(){
    int t, n, k, m, ans;
    string s;
    cin >> t;
    while (t--){
        ans = 0;
        g.clear();
        cin >> n >> k >> s;
        g.assign(k/2+1, vi(26,0));
        maxs.assign(k/2+1, 0);
        m = n/k;
        for (int i = 0; i < (k+1)/2; ++i) {
            for (int j = 0; j < m; ++j) {
                maxs[i] = max(maxs[i], ++g[i][s[k*j + i]-'a']);
                maxs[i] = max(maxs[i], ++g[i][s[k*(j+1)-(i+1)]-'a']);
            }
        }
        for (int l = 0; l < k/2; ++l) {
            ans += (2*m - maxs[l]);
        }
        if (k%2 == 1) {
            ans += (m - maxs[k / 2 ] / 2);
        }
        cout << ans << "\n";
    }
}