#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edges;
vector <int> ap;

int main(){
    int n, u, v;
    cin >> n;
    edges.reserve(n);
    ap.assign(n+1, 0);
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        edges[i] = {u,v};
        ap[u]++;
        ap[v]++;
    }
    u = -1;
    for (int j = 1; j < n+1; ++j) {
        if (ap[j] > 2){
            u = j;
            break;
        }
    }
    int val = 0, others = 3;
    if (u == -1){
        for (int l = 0; l < n-1; ++l) cout << l << "\n";
        return 0;}
    for (int k = 0; k < n-1; ++k) {
        if ((edges[k].first == u || edges[k].second == u) && val < 3){
            cout << val++ << "\n";
        }else cout << others++ << "\n";

    }
}