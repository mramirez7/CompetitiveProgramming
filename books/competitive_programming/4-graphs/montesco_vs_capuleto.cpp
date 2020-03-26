#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;

vector<set<int>> g;
vi vis;

int bfs(int v){
    int flag = 1;
    queue <ii> q;
    q.push({v, 1});
    vis[v] = 1;
    int ans1 = 0;
    int ans2 = 0;
    while (q.size()){
        int u = q.front().first; int p = q.front().second; q.pop();
        if (vis[u] == 3-p) flag = 0;
        if (p == 1) ans1++;
        else ans2++;
        for (auto w: g[u]){
            if (vis[w] == p) flag = 0;
            if (!vis[w]) {
                q.push({w, 3 - p});
                vis[w] = 3-p;
            }
        }
    }
    return flag*max(ans1,ans2);
}

int main(){
    int t, n, m, u;
    cin >> t;
    while (t--){
        cin >> n;
        vis.assign(201, 0);
        g.clear();
        g.assign(201, set<int>());
        for (int i = 1; i <= n; ++i) {
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> u;
                if (u > n) continue;
                g[i].insert(u);
                g[u].insert(i);
            }
        }
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (!vis[k]) ans += bfs(k);
        }
        cout << ans << "\n";
    }
}