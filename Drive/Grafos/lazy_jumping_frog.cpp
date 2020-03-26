#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int dr[24] = {1, 0, -1, 0, 1, -1, -1, 1, 2, 0, -2, 0, 2, 1, -1, -2, -2, -1, 1, 2, 2, -2, -2, 2};
int dc[24] = {0, -1, 0, 1, -1, -1, 1, 1, 0, -2, 0, 2, -1, -2, -2, -1, 1, 2, 2, 1, -2, -2, 2, 2};
int C, R;

vector<vector<int>> dist;
int board[1005][1005];

int cost(int a){
    if (a < 4) return 2;
    if (a < 8) return 3;
    if (a < 12) return 5;
    if (a < 20) return 6;
    return 7;
}

int main(){
    int l, x1, y1, x2, y2;
    ii initial, goal;
    while (cin >> C >> R){
        if (!(C|R)) break;
        for (int i1 = 0; i1 < 1002; ++i1) {
            for (int i = 0; i < 1002; ++i) {
                board[i1][i] = 0;
            }
        }
        cin >> initial.first >> initial.second;
        cin >> goal.first >> goal.second;
        cin >> l;
        for (int k = 0; k < l; ++k) {
            cin >> x1 >> y1 >> x2 >> y2;
            for (int j = y1; j <= y2; ++j) {
                board[x1][j]++;
                board[x2+1][j]--;
            }
        }
        for (int i = 1; i <= C; ++i) {
            for (int j = 1; j <= R; ++j) {
                board[i][j] += board[i-1][j];
            }
        }
        dist.assign(C+1, vector <int> (R+1, INT_MAX/2));
        dist[initial.first][initial.second] = 0;
        priority_queue <pair<int,ii>> pq;
        pq.push({0, {initial.first, initial.second}});
        while (pq.size()){
            int u1 = pq.top().second.first, u2 = pq.top().second.second;
            int d = -pq.top().first; pq.pop();
            if (dist[u1][u2] < d) continue;
            for (int v = 0; v < 24; v++){
                if (u1+dc[v] <= 0 || u1+dc[v] > C || u2+dr[v] <= 0 || u2+dr[v] > R || board[u1+dc[v]][u2+dr[v]]) continue;
                int w = cost(v); ii V = {u1+dc[v], u2+dr[v]};
                if (dist[V.first][V.second] > d + w){
                    dist[V.first][V.second] = d+w;
                    pq.push({-dist[V.first][V.second], V});
                }
            }
        }
        if (dist[goal.first][goal.second] != INT_MAX/2) cout << dist[goal.first][goal.second] << "\n";
        else cout << "impossible\n";
    }
}