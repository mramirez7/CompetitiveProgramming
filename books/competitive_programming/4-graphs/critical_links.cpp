#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, par;
vector <ii> ans;
int cont;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    for (auto v: g[u]){
        if (!dis[v]){
            par[v] = u;
            dfs(v);
            if (low[v] > dis[u])
                ans.push_back({min(u,v), max(u,v)});
            low[u] = min(low[u], low[v]);
        }
        else if(v != par[u]){
            low[u] = min(low[u], dis[v]);
        }
    }
}

int main(){
    int n, u, v, w;
    string s;
    while (cin >> n){
        g.clear();
        g.assign(n+1, vi());
        for (int i = 0; i < n; ++i) {
            cin >> u >> s;
            w = stoi(s.substr(1, s.size()-2));
            for (int j = 0; j < w; ++j) {
                cin >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        ans.clear();
        cont = 1;
        for (int k = 0; k < n; ++k) {
            if (!dis[k]) dfs(k);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << " critical links\n";
        for (int l = 0; l < ans.size(); ++l) {
            cout << ans[l].first << " - " << ans[l].second << "\n";
        }
        cout << "\n";
    }
}