#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, par, vis, S;
map <string,int> mapeo;
map <int, string> mapeoinv;
int cont;

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
        int flaf = 0;
        while (1){
            if (flaf) cout << ", ";
            else flaf = 1;
            int v = S.back(); S.pop_back(); vis[v] = 0;
            cout << mapeoinv.find(v)->second;
            if (u == v) break;
        }
        cout << "\n";
    }
}

int main(){
    int n, m, u, v, w, cs = 0, p;
    string s, ss;
    while (cin >> n >> m){
        if (!(n|m)) break;
        if (cs++) cout << "\n";
        g.clear();
        g.assign(n+1, vi());
        mapeoinv.clear();
        mapeo.clear();
        p = 0;
        for (int i = 0; i < m; ++i) {
            cin >> s >> ss;
            if (mapeo.find(s) == mapeo.end()) {
                mapeo.insert({s, p});
                mapeoinv.insert({p++, s});
            }
            if (mapeo.find(ss) == mapeo.end()) {
                mapeo.insert({ss, p});
                mapeoinv.insert({p++, ss});
            }
            g[mapeo.find(s)->second].push_back(mapeo.find(ss)->second);
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        vis.assign(n+1,0);
        cont = 1;
        cout <<  "Calling circles for data set " << cs << ":\n";
        for (int k = 0; k < n; ++k) {
            if (!dis[k]) dfs(k);
        }
    }
}