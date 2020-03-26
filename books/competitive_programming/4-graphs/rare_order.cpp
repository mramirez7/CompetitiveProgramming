#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector <string> ind;
vector <vector<int>> g;
vector <int> vis;
set <int> st;
string ans;

void dfs(int v){
    vis[v] = 1;
    for (auto u: g[v]){
        if (!vis[u]) dfs(u);
    }
    ans += (char)(v+'A');
}

int main(){
    string s;
    while (cin >> s) {
        st.clear();
        ans = "";
        vis.assign(26, 0);
        g.clear();
        g.assign(26, vector<int>());
        ind.clear();
        ind.push_back(s);
        while (cin >> s) {
            if (s[0] == '#') break;
            ind.push_back(s);
        }
        for (int i = 0; i < ind.size(); ++i) {
            for (int j = 0; j < ind[i].size(); ++j) {
                st.insert(ind[i][j] - 'A');
            }
        }
        for (int k = 1; k < ind.size(); ++k) {
            string a = ind[k - 1];
            string b = ind[k];
            for (int i = 0; i < min(a.size(), b.size()); ++i) {
                if (a[i] == b[i]) continue;
                g[a[i] - 'A'].push_back(b[i] - 'A');
                break;
            }
        }
        for (auto x: st)
            if (!vis[x])
                dfs(x);
        for (int l = st.size()-1; l >= 0 ; --l) {
            cout << ans[l];
        }
        cout << endl;
    }
}