#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;

vi h, vis, par, ans;
vvi g;
int r2, cisize = 0;

bool dfs(int u){
    vis[u] = 1;
    for (auto v: g[u]) {
        if (!vis[v]) {
            par[v] = u;
            h[v] = h[u] + 1;
            if (dfs(v) && ans.size() < cisize){
                ans.push_back(u);
                return true;
            }
        }
        else if (vis[v] == 1){
            if (h[u] - h[v] + 1 >= r2 && !cisize){
                cisize = h[u] - h[v] + 1;
                ans.push_back(u);
                return true;
            }
        }
    }
    vis[u] = 2;
    return false;
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    g.assign(n+1, vi());
    vis.assign(n+1, 0);
    par.reserve(n+1);
    h.reserve(n+1);
    h[1] = 0;
    par[1] = 1;
    for (int j = 0; j < m; ++j) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    r2 = ceil(sqrt(n));
    dfs(1);
    if (ans.size()) {
        cout << "2\n" << ans.size() << "\n";
        for (int k = 0; k < ans.size(); ++k) {
            cout << ans[k] << " ";
        }
        cout << "\n";
        return 0;
    }
    vis.assign(n+1,0);
    vector <ii> edg;
    set <ii> st;
    edg.push_back({0,0});
    for (int i = 1; i <= n; ++i) {
        edg.push_back({(int)g[i].size(), i});
        st.insert({(int)g[i].size(), i});
    }
    ii a, b;
    for (int l = 0; l < r2; ++l) {
        a = (*st.begin());
        ans.push_back(a.second);
        st.erase(a);
        u = a.second;
        for (auto uu: g[u]){
            if (vis[uu]) continue;
            vis [uu] = 1;
            if (st.find({edg[uu].first, uu}) != st.end()){
                st.erase({edg[uu].first, uu});
            }
            for (auto vv: g[uu]){
                if (st.find({edg[vv].first, vv}) != st.end()){
                    st.erase({edg[vv].first, vv});
                    st.insert({--edg[vv].first, vv});
                }
            }
        }
    }
    cout << "1\n";
    for (int i1 = 0; i1 < r2; ++i1) {
        cout << ans[i1] << " ";
    }
    cout << "\n";
}