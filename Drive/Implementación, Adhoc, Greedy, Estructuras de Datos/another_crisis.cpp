#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int t;
long double EPS = 1E-9;

int dfs(int v){
    if (!adj[v].size()) return 1;
    int ans = 0;
    double child_needed = (double)t*(double)adj[v].size()/100.0;
    int needed;
    if (fabs(child_needed-(int)child_needed) < EPS) needed = (int)child_needed;
    else needed = (int)child_needed+1;
    vector <int> costos_hijos;
    for (int i = 0; i < adj[v].size(); ++i) {
        costos_hijos.push_back(dfs(adj[v][i]));
    }
    sort(costos_hijos.begin(), costos_hijos.end());
    for (int j = 0; j < needed; ++j) {
        ans += costos_hijos[j];
    }
    return ans;
}

int main(){
    int n, p;
    while (cin >> n >> t){
        if (!(n+t)) return 0;
        adj.assign(n+1, vector<int>());
        for (int i = 1; i <= n; ++i) {
            cin >> p;
            adj[p].push_back(i);
        }
        int a = dfs(0);
        cout << a << "\n";
    }
}