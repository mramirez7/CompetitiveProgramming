//ACCEPTED
//TAG: topSort
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector <long long> visited;
vector <int> leaves;
vector <int> top_sort;
long long ans = 0, ans2 = 0, MOD = 1000000007;
int n, l;


void dfs(int v){
    visited[v] = 1;
    if (v > l) ans++;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!visited[g[v][i]]) dfs(g[v][i]);
    }
    top_sort.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> l;
    visited.assign(n+1, 0);
    leaves.assign(n+1, 0);
    g.assign(n+1, vector <int>());
    int m, u;
    for (int i = 1; i <= l; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> u;
            if (u > l) {
                leaves[i]++;
            }
            g[i].push_back(u);
        }
    }
    dfs(1);
    reverse(top_sort.begin(), top_sort.end());
    visited.assign(n+1,0);
    visited[1] = 1;
    for (int k = 0; k < top_sort.size(); ++k) {
        ans2 += visited[top_sort[k]]*leaves[top_sort[k]]%MOD;
        ans2 %= MOD;
        for (int i = 0; i < g[top_sort[k]].size(); ++i) {
            visited[g[top_sort[k]][i]] += visited[top_sort[k]]%MOD;
        }
    }
    cout << ans2 << " " << ans << "\n";
}