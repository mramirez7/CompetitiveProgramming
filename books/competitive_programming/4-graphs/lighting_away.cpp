#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g, gi;
vi low, dis, par, vis, S;
int cont, scc;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    S.push_back(u);
    vis[u] = 1;
    for (auto v: g[u]) {
        if (!dis[v])
            dfs(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == dis[u]){
        set <int> sc;
        set <int> ed;
        while (1){
            int v = S.back(); S.pop_back(); vis[v] = 0;
            sc.insert(v);
            ed.insert(v);
            for (int i = 0; i < gi[v].size(); ++i) {
                ed.insert(gi[v][i]);
            }
            if (u == v) break;
        }
        if (ed.size() == sc.size()) scc++;
    }
}

int main(){
    int t, n, m, u, v, cs = 1;
    cin >> t;
    while (t--){
        cin >> n >> m;
        scc = 0;
        g.clear();
        gi.clear();
        gi.assign(n+1, vi());
        g.assign(n+1, vi());
        for (int j = 0; j < m; ++j) {
            cin >> u >> v;
            g[u].push_back(v);
            gi[v].push_back(u);
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        vis.assign(n+1,0);
        cont = 1;
        for (int k = 1; k <= n; ++k) {
            if (!dis[k]) dfs(k);
        }
        cout << "Case " << cs++ << ": " << scc << "\n";
    }
}