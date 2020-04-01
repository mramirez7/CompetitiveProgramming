// complexity: (|E| + |V|) * log |V|
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; // (weight, node), in that order
typedef vector <int> vi;
typedef vector<vi> vvi;

vector<vector<ii>> g; // graph
int N; // number of nodes
vi mindist; // min distance from source to each node
vi par; // parent of each node in shortest path from source

void dijkstra(int source) {
    par.assign(N, -1);
    mindist.assign(N, INT_MAX);
    mindist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q; // minheap
    q.emplace(0, source);
    while (!q.empty()) {
        ii p = q.top(); q.pop();
        int u = p.second, dist = p.first; // u = node, dist = mindist from source to u
        if (mindist[u] < dist) continue; // skip outdated improvements
        for (ii& e : g[u]) {
            int v = e.second, w = e.first;
            if (mindist[v] > dist + w) {
                mindist[v] = dist + w;
                par[v] = u;
                q.emplace(mindist[v], v);
            }
        }
    }
}