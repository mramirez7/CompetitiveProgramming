#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<vector<ii>> g;
vector<int> dist;
vector<int> parent;

int main(){
    cout<<setprecision(1) << fixed;
    int n, m, u, v, w, tc = 0;
    while (1){
        cin >> n >> m;
        if (!(n|m)) break;
        tc++;
        g.assign(n+1, vector <ii>());
        dist.assign(n+1, INT_MAX/2);
        parent.assign(n+1, -1);
        dist[1] = 0;
        parent[1] = 1;
        priority_queue <ii> pq;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            g[u].push_back({w, v});
            g[v].push_back({w, u});
        }
        pq.push({0, 1});
        while (pq.size()){
            ii p = pq.top(); pq.pop();
            u = p.second;
            int d = -p.first;
            if (dist[u] < d) continue;
            for (auto e: g[u]) {
                w = e.first; v = e.second;
                if (dist[v] > d + w){
                    dist[v] = d + w;
                    parent[v] = u;
                    pq.push({-dist[v], v});
                }
            }
        }
        int max_node = 1;
        pair <float, ii> max_edge = {0.0, {0,0}};
        for (int j = 1; j <= n; ++j) {
            if (dist[j] > dist[max_node]) max_node = j;
            for (int i = 0; i < g[j].size(); ++i) {
                if (abs(dist[j] - dist[g[j][i].second]) >= g[j][i].first) continue;
                else max_edge = max(max_edge, {(float) max(dist[j], dist[g[j][i].second]) + (float)(g[j][i].first - abs(dist[j] - dist[g[j][i].second]))/2,{j,g[j][i].second}});
            }
        }
        cout << "System #" << tc << "\n";
        if (max_edge.first <= (float)dist[max_node])
            cout << "The last domino falls after " << (float)dist[max_node] << " seconds, at key domino "<< max_node << ".\n";
        else
            cout << "The last domino falls after " << max_edge.first << " seconds, between key dominoes " << min(max_edge.second.first, max_edge.second.second)<< " and " << max(max_edge.second.first, max_edge.second.second)<< ".\n";
        cout << "\n";
    }
}