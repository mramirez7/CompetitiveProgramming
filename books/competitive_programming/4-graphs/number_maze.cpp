// complexity: (|E| + |V|) * log |V|
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; // (weight, node), in that order
typedef vector <int> vi;
typedef vector<vi> vvi;

vector<vector<ii>> g; // graph
int n,m; // number of nodes
vvi mindist; // min distance from source to each node
vvi board;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

void dijkstra(int x, int y) {
    mindist.assign(n, vi(m ,INT_MAX));
    mindist[x][y] = 0;
    priority_queue <pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> q; // minheap
    q.push({0, {x,y}});
    while (!q.empty()) {
        pair<int,ii> p = q.top(); q.pop();
        ii u = p.second;
        int dist = p.first; // u = node, dist = mindist from source to u
        if (mindist[u.first][u.second] < dist) continue; // skip outdated improvements
        for (int i = 0; i < 4; ++i) {
            if (u.first + dc[i] >= 0 && u.first + dc[i] < n && u.second + dr[i] >= 0 && u.second + dr[i] < m) {
                ii v = {u.first+dc[i] , u.second+dr[i]};
                int w = board[u.first+dc[i]][u.second+dr[i]];
                if (mindist[v.first][v.second] > dist + w) {
                    mindist[v.first][v.second] = dist + w;
                    q.emplace(mindist[v.first][v.second], v);
                }
            }
        }
    }
}

int main(){
    int t, u, v, w;
    cin >> t;
    while (t--){
        cin >> n >> m;
        board.clear();
        board.assign(n, vi());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> u;
                board[i].push_back(u);
            }
        }
        dijkstra(0, 0);
        cout << mindist[n - 1][m - 1]+board[0][0] << "\n";
    }
}