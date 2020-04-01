/* ============== */
/*  Edmonds Karp  */
/* ============== */
// complexity: |V| * |E|^2
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define INF 1000000000
#define MAX_V 5051

int res[MAX_V][MAX_V], vert[105][105]; //residual capacities
int mf, f, s, t, cs = 1;
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

void edmonsKarp(){
    mf = 0;
    while (1) {
        //run BFS to find aumenting path
        f = 0;
        bitset<MAX_V> vis;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        p.assign(MAX_V, -1); //reset parents
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            //if (u == t) break; //not necesary, check goto below
            for (int j = 0; j < (int) AdjList[u].size(); j++) {  // we use AdjList here!
                int v = AdjList[u][j];
                if (res[u][v] > 0 && !vis[v]) {
                    vis[v] = true, q.push(v), p[v] = u;
                    if (v == t) { //target found!!
                        goto end_bfs;
                    }
                }
            }
        }
        end_bfs:
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }
    printf("Network %d\nThe bandwidth is %d.\n\n", cs++, mf);                              // this is the max flow value
}

int main() {
    int V, k, c, u, v, w, y, z;
    while (1) {
        cin >> V;
        if (!V) break;
        for (int j = 0; j < V*V/2; ++j) {
            for (int i = 0; i < V*V/2; ++i) {
                res[j][i] = 0;
            }
        }
        AdjList.assign(V+10+V*(V-1)/2, vi());
        cin >> s >> t >> c;
        for (int i = 0; i < c; ++i) {
            cin >> u >> v >> w;
            if (!w) continue;
            if (u > v) swap(u,v);
            if (res[u][v]){
                res[u][v] += w;
                y = vert[u][v];
                res[v][y] += w;
                res[y][u] += w;
            }
            else {
                AdjList[u].push_back(v);
                res[u][v] = w;
                vert[u][v] = ++V;
                AdjList[v].push_back(V);
                AdjList[V].push_back(u);
                res[v][V] = w;
                res[V][u] = w;
            }
        }
        edmonsKarp();
    }
    return 0;
}