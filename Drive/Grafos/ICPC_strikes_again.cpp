#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
vector <ll> sig;
vector <set<int>> w;
vector <set<int>> ig;
vector <vector<int>> g;
vector <int> vis;
vector <int> tp;
vector <int> ans;

void dfs(int v){
    vis[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        if (!vis[g[v][i]]) dfs(g[v][i]);
    }
    tp.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, e;
    int auxd, auxw, aux;
    while (cin >> t >> e){
        if (!(t|e)) return 0;
        cout << "*****\n";
        sig.assign(t+1,0);
        ans.assign(e+1,0);
        w.assign(t+1, set<int>());
        ig.assign(t+1, set<int>());
        g.assign(t+1, vector<int>());
        vis.assign(t+1, false);
        tp.clear();
        for (int i = 1; i <= t; ++i) {
            cin >> sig[i] >> auxd >> auxw;
            for (int j = 0; j < auxd; ++j) {
                cin >> aux;
                g[i].push_back(aux);
            }
            for (int k = 0; k < auxw; ++k) {
                cin >> aux;
                w[i].insert(aux);
            }
        }
        for (int l = 1; l < t+1; ++l) {
            if (!vis[l]) dfs(l);
        }
        for (int m = 1; m < t+1; ++m) {
            for (int i = 0; i < g[tp[m-1]].size(); ++i) {
                sig[tp[m-1]] += sig[g[tp[m-1]][i]];
            }
        }
        for (int m = t-1; m >= 0; m--) {
            for (int i = 0; i < g[tp[m]].size(); ++i) {
                for (auto x: w[tp[m]])
                    ig[g[tp[m]][i]].insert(x);
                for (auto x: ig[tp[m]])
                    ig[g[tp[m]][i]].insert(x);
            }
        }
        for (int n = 1; n <= t; ++n) {
            for (auto x: w[n]){
                if (ig[n].find(x) == ig[n].end())
                    ans[x] += sig[n];
            }
        }
        for (int i1 = 1; i1 <= e; ++i1) {
            cout << i1 << " " << ans[i1] << "\n";
        }
    }
}