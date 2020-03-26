//ACCEPTED
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector <pair<long , long>> vertex;
vector <int> visited;
map <pair<long , long>, int> mapeo;

int bfs(int v){
    int set_1 = 1;
    int set_2 = 0;
    int flag = 1;
    queue <pair<int,int>> q;
    q.push({v, flag});
    while (q.size()){
        v = q.front().first, flag = q.front().second^1;
        q.pop();
        for (auto i: graph[v]) {
            if (!visited[i]){
                visited[i] = 1;
                q.push({i,flag});
                if (flag) set_1++;
                else set_2++;
            }
        }
    }
    return min(set_1, set_2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v, u;
    while (cin >> n){
        graph.clear();
        graph.assign(n, vector<int>());
        vertex.clear();
        vertex.reserve(n);
        mapeo.clear();
        visited.clear();
        visited.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> v >> u;
            vertex[i] = {v,u};
            mapeo.insert({{v,u}, i});
        }
        for (int j = 0; j < n; ++j) {
            for (int i = -5; i <= 5; ++i) {
                for (int k = -5; k <= 5; ++k) {
                    if (i == 0 && k == 0) continue;
                    if(i*i + k*k > 25) continue;
                    if (mapeo.find({vertex[j].first+i,vertex[j].second + k}) != mapeo.end()){
                        graph[j].push_back(mapeo.find({vertex[j].first+i,vertex[j].second + k})->second);
                    }
                }
            }
        }
        int min_sub_set = 0;
        for (int k = 0; k < n; ++k) {
            if (!visited[k]){
                visited[k] = 1;
                min_sub_set += bfs(k);
            }
        }
        cout << min_sub_set << "\n";
    }
}