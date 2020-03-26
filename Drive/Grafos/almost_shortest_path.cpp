#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int W[505][505];
vector <set <int>> g;
vector<int> dist;
vector<vector<int>> parent;
vector<vector<int>> isInABestPath;
int n, s, d, mincost;
int m, u, v, w;

void dfs(int p){
    if (parent[p][0] == p) return;
    for (int i = 0; i < parent[p].size(); ++i) {
        g[parent[p][i]].erase(p);
        W[parent[p][i]][p] = INT_MAX/2;
        dfs(parent[p][i]);
    }
}

int dijkstra(){
    dist.assign(n, INT_MAX/2);
    parent.assign(n, vector<int>());
    dist[s] = 0;
    parent[s].push_back(s);
    priority_queue <ii> pq;
    pq.push({0, s});
    while (pq.size()){
        ii p = pq.top(); pq.pop();
        u = p.second;
        int d = -p.first;
        if (dist[u] < d) continue;
        for (auto e: g[u]) {
            w = W[u][e]; v = e;
            if (dist[v] > d + w){
                parent[v].clear();
                parent[v].push_back(u);
                dist[v] = d + w;
                pq.push({-dist[v], v});
            }else if(dist[v] == d + w){
                parent[v].push_back(u);
            }
        }
    }
    return dist[d];
}

int main(){
    while (1){
        cin >> n >> m;
        if (!(n|m)) break;
        cin >> s >> d;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                W[k][i] = INT_MAX/2;
            }
        }
        g.assign(n, set<int>());
        isInABestPath.assign(n, vector <int>(n, 0));
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            g[u].insert(v);
            W[u][v] = w;
        }
        mincost = dijkstra();
        int ans = mincost;
        if (ans == INT_MAX/2) {cout << "-1" << endl;
            continue;}
        dfs(d);
        ans = dijkstra();
        if (ans != INT_MAX/2) cout << ans << endl;
        else cout << "-1\n";
    }
}