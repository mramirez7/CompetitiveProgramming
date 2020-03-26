#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vi ts;
vi cs;
vvi g;
vi vis;
int ans, g1, g2;

void dfs (int v, int c){
    vis[v] = 1;
    cs[v] = c;
    if (c == 2) ans = 2;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (!vis[u]){
            dfs(u, 3-c);
        }
        else if (cs[u] == c) {
            cs[v] = 3;
            ans = 3;
        }
    }
}

int main(){
    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n;
        ts.reserve(n+1);
        cs.reserve(n+1);
        g.clear();
        g.assign(n+1, vi());
        k = 1;
        for (int i = 0; i < n; ++i) {
            cin >> ts[i];
            if (!i) continue;
            if (ts[i] != ts[i-1]){
                g[i].push_back(i-1);
                g[i-1].push_back(i);
            }
        }
        ts[n] = ts[0];
        if (ts[n-1] != ts[0]){
            g[0].push_back(n-1);
            g[n-1].push_back(0);
        }
        vis.assign(n, 0);
        ans = 1;
        for (int i1 = 0; i1 < n; ++i1) {
            if (!vis[i1]) dfs(i1, 1);
        }



        cout << ans << "\n";
        for (int l = 0; l < n; ++l) {
            cout << cs[l] << " ";
        }
        cout << "\n";
    }
}