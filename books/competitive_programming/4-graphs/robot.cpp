#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vector <vvi> vis;
map <char, int> mapeo;
int ans;
int n, m, b1, b2, d1, d2;
string dir;
char d;

int dr[] = {0, 0, 0, 1, 2, 3, 0, 0, 0, -1, -2, -3};
int dc[] = {1, 2, 3, 0, 0, 0, -1, -2, -3, 0, 0, 0};

bool isValid(int i, int j){
    if (g[i][j] || g[i][j+1] || g[i+1][j] || g[i+1][j+1]) return false;
    return true;
}

int bfs(){
    vis[b1][b2][mapeo[dir[0]]] = 1;
    queue <pair<ii, ii>> q;
    q.push({{b1, b2},{mapeo[dir[0]], 0}});
    while (q.size()){
        ii u = q.front().first;
        int dis = q.front().second.second;
        int or_ = q.front().second.first; q.pop();
        //cout << u.first << " " << u.second << " " << or_ << "\n";
        if (u == (ii){d1, d2}) return dis;
        for (int v = or_*3; v < or_*3+3; v++){
            if (u.first + dr[v] >= 0 && u.first + dr[v] < n && u.second + dc[v] >= 0 && u.second + dc[v] < m){
                if (isValid(u.first + dr[v], u.second + dc[v]) && !vis[u.first + dr[v]][u.second + dc[v]][or_]){
                    vis[u.first + dr[v]][u.second + dc[v]][or_] = 1;
                    q.push({{u.first + dr[v], u.second + dc[v]},{or_,dis+1}});
                }else {
                    if (!isValid(u.first + dr[v], u.second + dc[v]))
                        break;
                    if (vis[u.first + dr[v]][u.second + dc[v]][or_])
                        continue;
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            if ((or_%2) != (i%2) && !vis[u.first][u.second][i]) {
                vis[u.first][u.second][i] = 1;
                q.push({{u.first, u.second},{i,  dis + 1}});
            }
        }
    }
    return -1;
}
int main(){
    int u, v;
    mapeo['n'] = 3;
    mapeo['s'] = 1;
    mapeo['e'] = 0;
    mapeo['w'] = 2;
    while (cin >> n >> m) {
        if (!(m|n)) break;
        g.assign(n, vi(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> u;
                g[i][j] = u;
            }
        }
        vis.assign(n, vvi(m,vi(4,0)));
        cin >> b1 >> b2 >> d1 >> d2 >> dir;
        b1--; b2--; d1--; d2--; n--; m--;
        if (isValid(d1, d2) && isValid(b1, b2))
            cout << bfs() << "\n";
        else cout << "-1\n";
    }
}