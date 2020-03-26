//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

int dist[150][150];

int main(){
    int n, m, q, u, v, w, flag = 0;
    while (cin >> n >> m >> q){
        if (!(n+m+q)) return 0;
        if (flag) cout << "\n";
        else flag = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INT_MAX/2;
                if (i==j) dist[i][i] = 0;
            }
        }
        for (int k = 0; k < m; ++k) {
            cin >> u >> v >> w;
            dist[u][v] = min(w, dist[u][v]);
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] != INT_MAX/2 && dist[k][j] != INT_MAX/2)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] != INT_MAX/2 && dist[k][j] != INT_MAX/2 && dist[k][k] < 0)
                        dist[i][j] = -INT_MAX/2;


        for (int i1 = 0; i1 < q; ++i1) {
            cin >> u >> v;
            if (dist[u][v] == INT_MAX/2) cout << "Impossible\n";
            else if (dist[u][v] == -INT_MAX/2) cout << "-Infinity\n";
            else  cout << dist[u][v] << "\n";
        }
    }
}

