#include <bits/stdc++.h>
using namespace std;

//TARJAN

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, vis, S;
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
        scc++;
        while (1){ //sacamos del stack el scc
            int v = S.back(); S.pop_back(); vis[v] = 0;
            if (u == v) break;
        }
    }
}

int main(){
    int n, m;
    //generar grafo
    low.assign(n+1,0);
    dis.assign(n+1,0);
    vis.assign(n+1,0);
    cont = 1;
    scc = 0;
    for (int k = 0; k < n; ++k) {
        if (!dis[k]) dfs(k);
    }
}