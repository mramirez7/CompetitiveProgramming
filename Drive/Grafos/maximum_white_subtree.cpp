#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;

vi col, vis, par, memo, ans;
vvi g;

void dfs(int u){
    vis[u] = 1;
    memo[u] = col[u];
    for (auto v: g[u]) {
        if (vis[v]) continue;
        par[v] = u;
        dfs(v);
        if (memo[v] > 0) memo[u] += memo[v];
    }
}

void dfs2(int u){
    vis[u] = 1;
    for (auto v: g[u]){
        if (vis[v]) continue;
        ans[v] = memo[v];
        if (memo[v] > 0)
            ans[v] += max(0,ans[par[v]] - memo[v]);
        else
            ans[v] += max(0,ans[par[v]]);
        dfs2(v);
    }
}

int main(){
    int n, u, v;
    cin >> n;
    g.assign(n+1, vi());
    vis.assign(n+1, 0);
    memo.assign(n+1, 0);
    ans.assign(n+1, 0);
    par.reserve(n+1);
    par[1] = 1;
    col.reserve(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
        if (!col[i]) col[i] = -1;
    }
    for (int j = 0; j < n-1; ++j) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    vis.assign(n+1, 0);
    ans[1] = memo[1];
    dfs2(1);
    for (int k = 1; k <= n; ++k) {
        cout << ans[k] << " ";
    }
    cout << "\n";
}