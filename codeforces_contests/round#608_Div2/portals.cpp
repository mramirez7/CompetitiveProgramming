#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector <int> a;
vector <int> b;
vector <int> c;
vector <int> last_portal;
vector <vector<pair<int, int>>> back;
int memo[5002][5002];

int main(){
    int u, v;
    cin >> n >> m >> k;
    a.reserve(n);
    b.reserve(n);
    c.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int l = 0; l < n; ++l) last_portal.push_back(l);
    for (int j = 0; j < m; ++j) {
        cin >> u >> v; u--; v--;
        last_portal[v] = max(last_portal[v], u);
    }
    back.assign(n, vector<pair<int,int>>());
    for (int i1 = 0; i1 < n; ++i1)
        back[last_portal[i1]].push_back({-c[i1], i1});
    for (int k1 = 0; k1 < n; ++k1)
        sort(back[k1].begin(), back[k1].end());
    for (int j1 = 0; j1 <= n; ++j1)
        for (int i = 0; i < 5000; ++i)
            memo[j1][i] = j1 == n ? 0 : (int)-1e8;

    for (int l1 = n-1; l1 >= 0; l1--) {
        for (int i = 0; i <= 5000; ++i) {
            if (a[l1] > i) continue;
            int warriors = i + b[l1];
            int value = 0;
            memo[l1][i] = max(memo[l1][i], memo[l1+1][warriors]);
            for (int j = 0; j < back[l1].size(); ++j) {
                if (warriors >= j+1)
                    value += c[back[l1][j].second];
                else break;
                memo[l1][i] = max(memo[l1][i], memo[l1+1][warriors-j-1]+value);
            }
        }
    }
    if (memo[0][k] >= 0) cout << memo[0][k] << "\n";
    else cout << "-1\n";
}