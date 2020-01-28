//WA
//pasa todos los test oficiales
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector <pair<long , long>> vertex;
vector <int> visited;

int bfs(int v){
    int set_1 = 1;
    int set_2 = 0;
    int flag = 1;
    queue <pair<int,int>> q;
    q.push({v, flag});
    while (q.size()){
        //cout << q.size() << " size\n";
        v = q.front().first, flag = q.front().second^1;
        q.pop();
        for (auto i: graph[v]) {
            //cout << "v: " << v << " i: " <<i <<"\n";
            if (!visited[i]){
                //cout <<"if\n";
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
        visited.clear();
        visited.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> v >> u;
            vertex[i] = {v,u};
        }
        for (int j = 0; j < n-1; ++j) {
            for (int i = j+1; i < n; ++i) {
                if ((long long)((vertex[j].first-vertex[i].first)*(vertex[j].first-vertex[i].first)) + (long long)((vertex[j].second-vertex[i].second)*(vertex[j].second-vertex[i].second)) <= 25){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
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