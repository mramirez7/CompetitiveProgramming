#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> adj;
vector <int> reachable;
int ans;

void dfs(int w){
    for (auto i : adj[w]) {
        if (!reachable[i]){
            reachable[i] = 1;
            ans--;
            dfs(i);
        }
    }
}

int main(){
    int n, v, u;
    while (1){
        cin >> n;
        if (!n) break;
        adj.clear();
        adj.assign(n+1, vector <int>());
        while (1){
            cin >> v;
            if (!v) break;
            while (1){
                cin >> u;
                if (!u) break;
                adj[v].push_back(u);
            }
        }
        cin >> v;
        for (int i = 0; i < v; ++i) {
            cin >> u;
            reachable.assign(n+1, 0);
            ans = n;
            dfs(u);
            cout << ans;
            for (int j = 1; j <= n; ++j) {
                if (!reachable[j])
                    cout << " " << j;
            }
            cout << "\n";
        }
    }
}