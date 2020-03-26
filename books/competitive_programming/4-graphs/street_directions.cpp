#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, par, vis;
int cont;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    vis[u] = 1;
    for (auto v: g[u]){
        if (!vis[v]){
            cout << u << " " << v << "\n";
            par[v] = u;
            dfs(v);
            if (low[v] > dis[u])
                cout << v << " " << u << "\n";
            low[u] = min(low[u], low[v]);
        }
        else if(v != par[u]){
            if (vis[v] == 1)
                cout << u << " " << v << "\n";
            low[u] = min(low[u], dis[v]);
        }
    }
    vis[u] = 2;
}

int main(){
    int n, m, u, v, cases = 0;
    while (cin >> n >> m){
        if (!(n|m)) break;
        cout << ++cases << "\n\n";
        g.clear();
        g.assign(n+1, vi());
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        vis.assign(n+1,0);
        cont = 1;
        dfs(1);
        cout << "#\n";
    }
}