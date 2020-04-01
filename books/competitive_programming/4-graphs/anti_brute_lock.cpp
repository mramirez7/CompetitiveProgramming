//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[512]; //representantes
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

vector <string> keys;
int cost(int i, int j){
    int ans = 0;
    for (int k = 0; k < 4; ++k) {
        int u = (int)(keys[i][k] - '0');
        int v = (int)(keys[j][k] - '0');
        ans += min(abs(u-v), 10 - abs(u-v));
    }
    return ans;
}

int main(){
    int t, n, m, u, v, w, ans;
    string r, s;
    cin >> t;
    while (t--){
        keys.clear();
        ans = 0;
        cin >> n;
        for (int i = 0; i <= n; ++i)
            rep[i] =  i;
        priority_queue <pair <int, ii>> edges;
        for (int j = 0; j < n; ++j) {
            cin >> r;
            keys.push_back(r);
        }
        keys.push_back("0000");
        for (int l = 0; l < n; ++l) {
            for (int i = l+1; i < n; ++i) {
                edges.push({-cost(l, i),{l,i}});
            }
        }
        w = 25;
        for (int k = 0; k < n; ++k)
            w = min(w, cost(k, n));
        ans = w;
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

