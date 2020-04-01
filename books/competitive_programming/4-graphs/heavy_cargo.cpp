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
map <string, int> mapeo;

int target, root, ans;

bool dfs(int u){
    vis[u] = 1;
    if (g[u].size() == 1 && u != root || u == target){
        if (u == target)
            return true;
        else
            return false;
    }
    for (auto v: g[u]){
        if (vis[v.second]) continue;
        if (dfs(v.second)){
            ans = min(ans, v.first);
            return true;
        }
    }
    return false;
}

int main(){
    int n, m, u, v, w, cs = 1, c;
    string s, t;
    while (1) {
        c = 0;
        cin >> n >> m;
        ans = INT_MAX;
        if (!(n|m)) break;
        mapeo.clear();
        vis.assign(n,0);
        g.clear();
        g.assign(n, vector<ii>());
        for (int i = 0; i <= n; ++i)
            rep[i] = i;
        priority_queue <pair<int, ii>> edges;
        for (int j = 0; j < m; ++j) {
            cin >> s >> t >> w;
            if (mapeo.find(s) == mapeo.end()){
                mapeo.insert({s, c++});
            }
            if (mapeo.find(t) == mapeo.end()){
                mapeo.insert({t, c++});
            }
            u = mapeo.find(s)->second;
            v = mapeo.find(t)->second;
            edges.push({w, {u,v}});
        }
        cin >> s >> t;
        u = mapeo.find(s)->second;
        v = mapeo.find(t)->second;
        root = u; target = v;
        int repU, repV;
        while (n != 1 && edges.size()) {
            w = edges.top().first;
            v = edges.top().second.first;
            u = edges.top().second.second;
            edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV) {
                union_(u, repV);
                g[u].push_back({w,v});
                g[v].push_back({w,u});
                n--;
            }
        }
        dfs(root);
        cout << "Scenario #" << cs++ << "\n";
        cout << ans << " tons\n\n";
    }
}

