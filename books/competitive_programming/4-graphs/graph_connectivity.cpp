#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <vector<int>> graph;
int n, ans;

void dfs(int v){
    visited[v] = 1;
    for (auto i: graph[v]) {
        if (!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    int t, flag = 1;
    string arist;
    cin >> t;
    cin >> arist;
    while (t--){
        if (flag) flag = 0;
        else cout << "\n";
        ans = 0;
        graph.clear();
        n = arist[0]-'A';
        graph.assign(n+1,vector<int>());
        visited.assign(n+1,0);
        while (cin >> arist){
            if (arist.size()<=1) break;
            int u = (int)arist[0]-'A', v = (int)arist[1]-'A';
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i <= n ; ++i) {
            if (!visited[i]){
                ans++;
                dfs(i);
            }
        }
        cout << ans << "\n";
    }
}