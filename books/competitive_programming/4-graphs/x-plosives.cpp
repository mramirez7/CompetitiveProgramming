//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi g;
vi vis;

void dfs(int t){
    vis[t] = 1;
    for (auto r: g[t]){
        if (!vis[r]) dfs(r);
    }
}

int main(){
    int u, v, ans;
    while (cin >> u >> v){
        g.clear();
        g.assign(100010, vi());
        vis.assign(100010, 0);
        ans = 0;
        set <int> s1;
        s1.insert(u);
        s1.insert(v);
        g[u].push_back(v);
        g[v].push_back(u);
        int edges = 1;
        int comp = 0;
        while (1){
            cin >> u;
            if (u == -1) break;
            cin >> v;
            edges++;
            s1.insert(u);
            s1.insert(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (auto a: s1){
            if (!vis[a]){
                comp++;
                dfs(a);
            }
        }
        cout << max(0, edges - (int)(s1.size()-comp)) <<"\n";
    }
}

