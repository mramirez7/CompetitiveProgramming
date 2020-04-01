#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vector <vector <string>> ans;
vi low, dis, par, vis, S;
map <string,int> mapeo;
map <int, string> mapeoinv;
int cont, scc;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    S.push_back(u);
    vis[u] = 1;
    for (auto v: g[u]) {
        if (!dis[v])
            dfs(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == dis[u]){
        scc++;
        ans.push_back(vector<string>());
        while (1){
            int v = S.back(); S.pop_back(); vis[v] = 0;
            ans[ans.size()-1].push_back(mapeoinv.find(v)->second);
            if (u == v) break;
        }
        sort(ans[ans.size()-1].begin(), ans[ans.size()-1].end());
    }
}

int main(){
    int n, m, p, cs = 0, in[6];
    string s[6];
    while (cin >> m){
        if (!m) break;
        if (cs++) cout << "\n";
        g.clear();
        ans.clear();
        n = 0;
        mapeoinv.clear();
        mapeo.clear();
        p = 0;
        scc = 0;
        g.assign(26, vi());
        for (int i = 0; i < m; ++i) {
            for (int l = 0; l < 6; ++l) cin >> s[l];
            for (int j = 0; j < 6; ++j) {
                if (mapeo.find(s[j]) == mapeo.end()) {
                    n++;
                    mapeo.insert({s[j], p});
                    mapeoinv.insert({p++, s[j]});
                }
                in[j] = mapeo.find(s[j])->second;
            }
            for (int k = 0; k < 5; ++k) {
                g[in[5]].push_back(in[k]);
            }
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        vis.assign(n+1,0);
        cont = 1;
        for (int k = 0; k < n; ++k) {
            if (!dis[k]) dfs(k);
        }
        sort(ans.begin(), ans.end());
        for (int i1 = 0; i1 < scc; ++i1) {
            for (int i = 0; i < ans[i1].size(); ++i) {
                if (i) cout << " ";
                cout << ans[i1][i];
            }
            cout << "\n";
        }
    }
}