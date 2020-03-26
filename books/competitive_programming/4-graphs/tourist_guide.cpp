#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi low, dis, par;
set <string> ans;
map <string,int> mapeo;
map <int, string> mapeoinv;
int root, root_sons, cont;

void dfs(int u){
    dis[u] = cont;
    low[u] = cont++;
    for (auto v: g[u]){
        if (!dis[v]){
            if (root == u) root_sons++;
            par[v] = u;
            dfs(v);
            if (low[v] >= dis[u] && u != root)
                ans.insert(mapeoinv.find(u)->second);
            low[u] = min(low[u], low[v]);
        }
        else if(v != par[u]){
            low[u] = min(low[u], dis[v]);
        }
    }
}

int main(){
    int n, u, v, w, cs = 0;
    string s, ss;
    while (cin >> n){
        if (!n) break;
        if (cs++) cout << "\n";
        g.clear();
        g.assign(n+1, vi());
        mapeoinv.clear();
        mapeo.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s;
            mapeo.insert({s,i});
            mapeoinv.insert({i,s});
        }
        cin >> w;
        for (int k = 0; k < w; ++k) {
                cin >> s >> ss;
                g[mapeo.find(s)->second].push_back(mapeo.find(ss)->second);
                g[mapeo.find(ss)->second].push_back(mapeo.find(s)->second);
        }
        low.assign(n+1,0);
        dis.assign(n+1,0);
        par.assign(n+1,0);
        ans.clear();
        cont = 1;
        for (int k = 0; k < n; ++k) {
            root = k;
            root_sons = 0;
            if (!dis[k]) dfs(k);
            if (root_sons > 1) ans.insert(mapeoinv.find(k)->second);
        }
        cout << "City map #" << cs << ": " << ans.size() << " camera(s) found\n";
        for (auto l : ans) {
            cout << l << "\n";
        }
    }
}