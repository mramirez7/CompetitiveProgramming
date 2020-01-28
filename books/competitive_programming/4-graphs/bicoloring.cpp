#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <int> colors;
vector <vector<int>> graph;

int main(){
    int t, n, l, u, v, flag;
    while (1){
        flag = 1;
        cin >> n;
        if (!n) break;
        cin >> l;
        graph.clear();
        visited.assign(n,0);
        colors.assign(n,-1);
        graph.assign(n, vector <int>());
        for (int i = 0; i < l; ++i) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue <pair<int, int>> cola;
        cola.push({0,1});
        int color;
        while (cola.size()){
            v = cola.front().first; color = cola.front().second;
            cola.pop();
            colors[v] = color;
            visited[v] = 1;
            for (auto i: graph[v]) {
                if (!visited[i]) cola.push({i, (color+1)%2});
                else {
                    if (colors[i] != (color+1)%2) flag = 0;
                    while (cola.size()) cola.pop();
                }
            }
        }
        if (!flag) cout << "NOT ";
        cout << "BICOLORABLE.\n";
    }
}