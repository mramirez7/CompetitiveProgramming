//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dag;
vector<vector<int>> dp;

int disjoint(int v, int u){ // v < u
    if (dp[v][u] == 1) return 1;
    if (!v){
        dp[v][u] = 1;
        return 1;
    }
    if(!dp[v][u]) return 0;
    for (auto i: dag[u]) {
        if (v != i && disjoint(min(i,v), max(i,v))){
            dp[v][u] = 1;
            return 1;
        }
    }
    dp[v][u] = 0;
    return 0;
}

int main(){
    int c, p;
    int v, u, ans;
    while (cin >> c >> p){
        ans = 0;
        dag.assign(c, vector<int>());
        dp.assign(c, vector<int>());
        for (int k = 0; k < c; ++k) {
            dp[k].assign(c,-1);
        }
        for (int i = 0; i < p; i++) {
            cin >> u >> v;
            u--; v--;
            dag[v].push_back(u);
        }
        for (int j = 0; j < c; ++j) {
            for (int i = j+1; i < c; ++i) {
                ans += disjoint(j, i);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

