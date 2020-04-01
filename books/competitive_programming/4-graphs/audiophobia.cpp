//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[202]; //representantes
vector <vector<ii>> g;

int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}
vi vis;

int target, root, ans;
vi h; vector <ii> par;

void dfs(int u){
    vis[u] = 1;
    h[u] = h[par[u].second] + 1;
    for (auto v: g[u]){
        if (vis[v.second]) continue;
        par[v.second] = {v.first,u};
        dfs(v.second);
    }
}

int main(){
    int n, m, q, u, v, w, cs = 1;
    string s, t;
    while (1) {
        cin >> n >> m >> q;
        if (!(n|m|q)) return 0;
        if (cs != 1) cout << "\n";
        par.assign(n+1, {0,0});
        h.assign(n+1, 0);
        vis.assign(n+1,0);
        g.clear();
        g.assign(n+1, vector<ii>());
        for (int i = 0; i <= n; ++i)
            rep[i] = i;
        priority_queue <pair<int, ii>> edges;
        for (int j = 0; j < m; ++j) {
            cin >> u >> v >> w;
            edges.push({-w, {u,v}});
        }
        int repU, repV, aux_n = n;
        while (aux_n != 1 && edges.size()) {
            w = edges.top().first;
            v = edges.top().second.first;
            u = edges.top().second.second;
            edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV) {
                union_(u, repV);
                g[u].push_back({-w,v});
                g[v].push_back({-w,u});
                aux_n--;
            }
        }
        int trees = 0;
        for (int l = 1; l <= n; ++l) {
            if (!vis[find(l)]){
                h[find(l)] = -1;
                par[find(l)] = {0,find(l)};
                dfs(find(l));
            }
        }
        cout << "Case #" << cs++ << "\n";
        for (int k = 0; k < q; ++k) {
            cin >> u >> v;
            if (find(u) != find(v)){
                cout << "no path\n";
                continue;
            }
            ans = 0;
            if (h[u] < h[v]) swap(u, v);
            while (h[u] > h[v]) {
                ans = max(ans, par[u].first);
                u = par[u].second;
            }
            while (u != v) {
                ans = max(ans, par[u].first);
                u = par[u].second;
                ans = max(ans, par[v].first);
                v = par[v].second;
            }
            cout << ans << "\n";
        }
    }
}

