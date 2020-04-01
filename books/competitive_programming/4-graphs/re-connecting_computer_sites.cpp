//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[1000010]; //representantes
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
    int n, m, u, v, w, flag = 0;
    ll ans1, ans2;
    while (cin >> n){
        if (flag) cout << "\n";
        flag = 1;
        ans1 = ans2 = 0;
        for (int i = 0; i < n; ++i)
            rep[i] =  i;
        priority_queue <pair <int, ii>> edges;
        for (int j = 0; j < n-1; ++j) {
            cin >> u >> v >> w;
            edges.push({-w,{--u,--v}});
            ans1 += w;
        }
        for (int k = 0; k < 2; ++k) {
            cin >> m;
            while (m--) {
                cin >> u >> v >> w;
                if (!k) edges.push({-w,{--u,--v}});
            }
        }
        cout << ans1 << "\n";
        int repU, repV;
        while (n != 1 && edges.size()){
            w = edges.top().first; v = edges.top().second.first; u = edges.top().second.second; edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV){
                union_(u, repV);
                ans2 -= w;
                n--;
            }
        }
        cout << ans2 << "\n";
    }
    return 0;
}

