#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, par, art;
vector <ii> ans;
int root, root_sons, cont;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    for (auto v: g[u]){
        if (!dis[v]){
            if (root == u) root_sons++;
            par[v] = u;
            dfs(v);
            if (low[v] >= dis[u] && u != root)
                art[u]++;
            low[u] = min(low[u], low[v]);
        }
        else if(v != par[u]){
            low[u] = min(low[u], dis[v]);
        }
    }
}

int main(){
    int n, m, u, v, w, cs = 0;
    while (cin >> n >> m){
        if (!(n|m)) break;
        cs++;
        g.clear();
        g.assign(n, vi());
        while (1){
            cin >> u >> v;
            if (u == -1 && v == u) break;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        low.assign(n,0);
        dis.assign(n,0);
        par.assign(n,0);
        art.assign(n,0);
        ans.clear();
        cont = 1;
        root = 0;
        root_sons = 0;
        dfs(root);
        if (root_sons > 1) art[0] = root_sons-1;
        for (int i = 0; i < n; ++i) {
            ans.push_back({-art[i]-1, i});
        }
        sort(ans.begin(), ans.end());
        for (int j = 0; j < m; ++j) {
            cout << ans[j].second << " " << -ans[j].first << "\n";
        }
        cout << "\n";
    }
}