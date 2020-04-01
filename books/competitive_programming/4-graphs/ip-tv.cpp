//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map <string, int> mapeo;

int rep[2010]; //representantes
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
    int t, n, m, u, v, w, c, flag = 0;
    string r, s;
    ll ans;
    cin >> t;
    while (t--){
        cin >> n >> m;
        if (flag) cout << "\n";
        flag = 1;
        ans = 0;
        c = 0;
        mapeo.clear();
        for (int i = 0; i < n; ++i)
            rep[i] =  i;
        priority_queue <pair <int, ii>> edges;
        for (int j = 0; j < m; ++j) {
            cin >> r >> s >> w;
            if (mapeo.find(r) == mapeo.end())
                mapeo.insert({r, c++});
            if (mapeo.find(s) == mapeo.end())
                mapeo.insert({s, c++});
            u = mapeo.find(r)->second;
            v = mapeo.find(s)->second;
            edges.push({-w,{u,v}});
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
    }
    return 0;
}

