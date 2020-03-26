//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi vis;
int g1, g2;

int dfs(int v, int c){
    vis[v] = c;
    if (c == 1) g1++;
    else g2++;
    for (auto u: g[v]){
        if (vis[u] && vis[u] != 3-c)
            return -1;
        if (!vis[u])
            if (dfs(u, 3-c) == -1)
                return -1;
    }
    return max(1,min(g1,g2));
}

int main(){
    int t, n, m, u, v;
    cin >> t;
    while (t--){
        cin >> n >> m;
        g.clear();
        g.assign(n,vi());
        vis.assign(n,0);
        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0, flag;
        for (int j = 0; j < n; ++j) {
            if (!vis[j]) {
                g1 = 0;
                g2 = 0;
                flag = ans;
                ans += dfs(j, 1);
                if (flag > ans){
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}