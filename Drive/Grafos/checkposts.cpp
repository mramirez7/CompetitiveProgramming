#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, vis, S, costs;
int cont, scc;
long long MOD = 1000000007;
long long ans1, ans2;

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
        int min_ = INT_MAX;
        int cant_min = (int)MOD;
        while (1){ //sacamos del stack el scc
            int v = S.back(); S.pop_back(); vis[v] = 0;
            if (costs[v] < min_){
                min_ = costs[v];
                cant_min = 1;
            }else if (costs[v] == min_) cant_min++;
            if (u == v) break;
        }
        ans1 += min_;
        ans2 *= cant_min%MOD;
        ans2 %= MOD;
    }
}

int main(){
    int n, m, u, v;
    cin >> n;
    ans1 = 0;
    ans2 = 1;
    costs.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i];
    }
    cin >> m;
    g.assign(n+1, vi());
    for (int j = 0; j < m; ++j) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    low.assign(n+1,0);
    dis.assign(n+1,0);
    vis.assign(n+1,0);
    cont = 1;
    scc = 0;
    for (int k = 1; k <= n; ++k) {
        if (!dis[k]) dfs(k);
    }
    cout << ans1 << " " << ans2 << "\n";
}