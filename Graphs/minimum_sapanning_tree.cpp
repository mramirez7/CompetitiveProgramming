//ACCEPTED
//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

int rep[10000]; //representantes
int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    //y es representante del otro conjunto
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
    int n, m, u, v, w;
    long long ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        rep[i] =  i;
    priority_queue <pair <int, pair <int, int>>> edges;
    while (m--) {
        cin >> u >> v >> w;
        edges.push({-w,{--u,--v}});
    }
    int repU, repV;
    while (n != 1 && edges.size()){
        w = edges.top().first; v = edges.top().second.first; u = edges.top().second.second; edges.pop();
        repU = find(u);
        repV = find(v);
        if (repU != repV){
            union_(u, repV);
            ans -= w;
            n--;
        }
    }
    cout << ans << "\n";
    return 0;
}

