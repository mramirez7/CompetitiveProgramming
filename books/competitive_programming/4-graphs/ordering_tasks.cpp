#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> g;
vector <int> ans;
vector <int> vis;

void dfs(int v){
    vis[v] = 1;
    for (auto u: g[v]){
        if (!vis[u]) dfs(u);
    }
    ans.push_back(v);
}

int main(){
    int n, m, u, v;
    while (cin >> n >> m){
        if (!(n|m)) return 0;
        g.clear();
        ans.clear();
        g.assign(n+1,vector<int>());
        vis.assign(n+1,0);
        while (m--){
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) dfs(i);
        }
        for (int j = n-1; j >= 0 ; --j) {
            if (j != n-1) cout << " ";
            cout << ans[j];
        }
        cout << "\n";
    }
}