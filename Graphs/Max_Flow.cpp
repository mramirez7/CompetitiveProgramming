/* ============== */
/*  Edmonds Karp  */
/* ============== */
// complexity: |n| * |E|^2
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define INF 1000000000
#define MAX_n 40

int res[MAX_n][MAX_n]; //residual capacities
int mf, f, s, t;
vi p;
vector<vi> g;

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
        bitset<MAX_n> vis;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        p.assign(MAX_n, -1); //reset parents
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            //if (u == t) break; //not necesary, check goto below
            for (int j = 0; j < (int) g[u].size(); j++) {  // we use g here!
                int v = g[u][j];
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
    printf("Max flow is %d.\n", mf);                              // this is the max flow value
}

int main() {
    int n;
    //initialize g and res
    g.assign(n, vi());
    //generar grafo, y res
}