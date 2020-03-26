//ACCEPTED
//TAG: Bellman-Ford
#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> g;
vector <int> dist;
int cost[1001][1001];

int main(){
    int t, n, m, u, v, w, flag;
    cin >> t;
    while (t--){
        cin >> n >> m;
        flag = 0;
        g.clear();
        dist.assign(n, INT_MAX/2);
        dist[0] = 0;
        g.assign(n+1, vector <int> ());
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            g[u].push_back(v);
            cost[u][v] = w;
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                for (int k = 0; k < g[i].size(); ++k) {
                    if (j == n-1 && dist[g[i][k]] > dist[i] + cost[i][g[i][k]]) flag = 1;
                    dist[g[i][k]] = min(dist[g[i][k]], dist[i] + cost[i][g[i][k]]);
                }
            }
        }
        if (!flag) cout << "not ";
        cout << "possible\n";
    }
}