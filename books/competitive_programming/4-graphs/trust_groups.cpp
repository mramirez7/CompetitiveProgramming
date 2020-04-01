#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
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
        while (1){
            int v = S.back(); S.pop_back(); vis[v] = 0;
            if (u == v) break;
        }
        scc++;
    }
}

int main(){
    int p, n, m, u, v;
    string r, s, t;
    while (cin >> n >> m){
        if (!(n|m)) break;
        scc = 0;
        p = 0;
        g.clear();
        g.assign(n+1, vi());
        map <string, int> mapeo;
        for (int i = 0; i < n; ++i) {
            cin >> r >> s;
            r += s;
            mapeo.insert({r, p++});
        }
        for (int j = 0; j < m; ++j) {
            cin >> r >> s;
            r += s;
            cin >> s >> t;
            s += t;
            g[mapeo.find(r)->second].push_back(mapeo.find(s)->second);
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        vis.assign(n+1,0);
        scc = 0;
        cont = 1;
        for (int k = 0; k < n; ++k) {
            if (!dis[k]) dfs(k);
        }
        cout << scc << "\n";
    }
}