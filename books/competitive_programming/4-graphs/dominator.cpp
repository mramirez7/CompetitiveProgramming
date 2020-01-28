#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <vector<int>> dominator;
int graph[100][100];
int n;

void dfs(int v, int cut){
    visited[v] = 1;
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] && !visited[i] && i != cut){
            dfs(i, cut);
        }
    }
}

int main(){
    int t, c = 0;
    cin >> t;
    string line;
    while (t--){
        cout << "Case " << ++c<<":\n";
        cin >> n;
        line = "+";
        for (int m = 0; m < 2*n-1; ++m) {
            line += "-";
        }
        line += "+";
        visited.assign(n,0);
        dominator.assign(n,vector<int>());
        for (int i = 0; i < n; ++i) {
            dominator[i].assign(n,0);
            for (int j = 0; j < n; ++j) {
                cin >> graph[i][j];
            }
        }
        dfs(0, 101);
        for (int k = 0; k < n; ++k) {
            if (visited[k]) dominator[0][k] = 1;
        }
        for (int l = 1; l < n; ++l) {
            visited.assign(n,0);
            dfs(0,l);
            for (int i = 0; i < n; ++i) {
                if (dominator[0][i] && !visited[i]) dominator[l][i] = 1;
            }
        }
        cout << line << "\n";
        for (int i1 = 0; i1 < n; ++i1) {
            cout << "|";
            for (int i = 0; i < n; ++i) {
                if (dominator[i1][i]) cout << "Y|";
                else cout << "N|";
            }
            cout << "\n"<<line << "\n";
        }
    }
}