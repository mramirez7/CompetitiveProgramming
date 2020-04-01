#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi vis;
map <int, int> mapeo;
int ans;

void bfs(int v, int d){
    vis[v] = 1;
    queue <ii> q;
    q.push({v, 0});
    while (q.size()){
        int u = q.front().first, dis = q.front().second; q.pop();
        if (dis > d) return;
        ans++;
        for (int vv: g[u]){
            if (!vis[vv]){
                vis[vv] = 1;
                q.push({vv, dis+1});
            }
        }
    }
}

int main(){
    int nc, cs = 1, u, v, mp;
    while (cin >> nc){
        if (!nc) break;
        g.clear();
        g.assign(31, vi());
        mapeo.clear();
        mp = 0;
        for (int i = 0; i < nc; ++i) {
            cin >> u >> v;
            if (mapeo.find(u) == mapeo.end())
                mapeo[u] = mp++;
            if (mapeo.find(v) == mapeo.end())
                mapeo[v] = mp++;
            u = mapeo[u];
            v = mapeo[v];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        while (1){
            cin >> u >> v;
            if (!(u|v)) break;
            ans = 0;
            if (mapeo.find(u) != mapeo.end()) {
                vis.assign(mp + 1, 0);
                bfs(mapeo[u], v);
            }
            cout << "Case " << cs++ << ": " <<mp-ans << " nodes not reachable from node " << u << " with TTL = " << v << ".\n";
        }
    }
}