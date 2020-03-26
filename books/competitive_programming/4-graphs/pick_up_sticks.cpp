#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;

vector <vi> g;
vi vis;
vi ans;
int flag;

void dfs(int v){
    vis[v] = 1;
    for (auto u: g[v]){
        if (vis[u] == 1){
            flag = 0;
            return;
        } else if (!vis[u])
            dfs(u);
    }
    vis[v] = 2;
    ans.push_back(v);
}

int main(){
    int n, m, u, v;
    while (cin >> n >> m){
        if (!(n|m)) break;
        flag = 1;
        ans.clear();
        g.clear();
        g.assign(n+1,vi());
        vis.assign(n+1,0);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) dfs(j);
        }
        if (!flag) cout << "IMPOSSIBLE\n";
        else
            for (int k = n-1; k >= 0; k--) {
                cout << ans[k] << "\n";
            }
    }
}