//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

vector <int> permutation;
int rep[1000000]; //representantes
int frec_rep[1000000];
vector<vector<int>> graph;

int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}


int main(){
    int n, m;
    int a, b, repa;
    cin >> n >> m;
    permutation.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
        rep[i] = i;
        frec_rep[i] = 0;
    }
    for (int j = 0; j < m; j++) {
        cin >> a >> b;
        a--; b--;
        repa = find(a);
        union_(b, repa);
    }
    graph.assign(n, vector<int>());
    for (int k = 0; k < n; k++) {
        graph[find(k)].push_back(permutation[k]);
    }
    for (int l = 0; l < n; l++) {
        if (graph[l].size()) sort(graph[l].begin(), graph[l].end());
        frec_rep[find(l)] += 1;
    }
    for (int i1 = 0; i1 < n; i1++) {
        repa = find(i1);
        cout << graph[repa][frec_rep[repa]-1] << " ";
        frec_rep[repa]--;
    }
    cout << "\n";
    return 0;
}

