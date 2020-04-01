/* ============== */
/*  Edmonds Karp  */
/* ============== */
// complexity: |V| * |E|^2

//RTE
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define INF 1000000000
#define MAX_V 40

int res[MAX_V][MAX_V]; //residual capacities
int mf, f, s, t;
vi p;
vector<vi> AdjList;

void augment(int v, int minEdge) {     // traverse BFS spanning tree from s to t
    if (v == s) { f = minEdge; return; }  // record minEdge in a global variable f
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v])); // recursive
        res[p[v]][v] -= f; res[v][p[v]] += f; }       // update
}

int main() {
    int V = 38, k, vertex, weight, total;
    string line;
    char app, pc;
    s = 0; t = 37;
    int wierd = 0;

    //initialize AdjList and res
    while (1) {
        AdjList.assign(V, vi());
        for (int i = 0; i < 38; ++i) {
            for (int j = 0; j < 38; ++j) {
                res[i][j] = 0;
            }
        }
        for (int l = 27; l < 37; ++l) {
            AdjList[l].push_back(37);
            AdjList[37].push_back(l);
            res[l][37] = 1;
        }
        total = 0;
        while (1) {
            if (scanf("%c", &app) == EOF) return 0;
            if (app == '\n' || app == '\r')
                break;
            scanf("%d", &weight);
            res[0][app - 'A'+1] = weight;
            AdjList[0].push_back(app - 'A'+1);
            AdjList[app - 'A'+1].push_back(0);
            total += weight;
            scanf("%c", &pc);
            while (1) {
                scanf("%c", &pc);
                if (pc == ';') {
                    scanf("%c", &pc);
                    scanf("%c", &pc);
                    break;
                }
                res[app - 'A'+1][pc - '0' + 27] = 1;
                AdjList[pc - '0' + 27].push_back(app - 'A'+1);
                AdjList[app - 'A'+1].push_back(pc - '0' + 27);
            }
        }
        mf = 0;
        while (1) {

            //run BFS to find aumenting path
            f = 0;
            bitset<MAX_V> vis; vis[s] = true;
            queue<int> q; q.push(s);
            p.assign(MAX_V, -1); //reset parents
            while (!q.empty()) {
                int u = q.front(); q.pop();
                //if (u == t) break; //not necesary, check goto below
                for (int j = 0; j < (int)AdjList[u].size(); j++) {  // we use AdjList here!
                    int v = AdjList[u][j];
                    if (res[u][v] > 0 && !vis[v]) {
                        vis[v] = true, q.push(v), p[v] = u;
                        if(v == t) { //target found!!
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
        //printf ("%d %d\n", total, mf);
        if (wierd){
            wierd = 0;
            continue;
        }else{
            wierd = 1;
        }
        if (total != mf ){
            printf("!\n");
            continue;
        }
        else {
            for (int m = 27; m < 37; ++m) {
                int flag = 0;
                for (int i = 1; i < 27; ++i) {
                    if (res[m][i]) {
                        printf("%c", i + 'A' - 1);
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    printf("_");
                }
            }
            printf("\n");
        }
    }
}