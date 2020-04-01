//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[200010]; //representantes
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
    int t, n, m, u, v, w, ans, sum_;
    ans = 0;
    while (1) {
        cin >> n >> m;
        ans = 0;
        sum_ = 0;
        if (!(n|m)) break;
        for (int i = 0; i <= n; ++i)
            rep[i] = i;
        priority_queue <pair<int, ii>> edges;
        for (int j = 0; j < m; ++j) {
            cin >> u >> v >> w;
            edges.push({-w, {u, v}});
            sum_ += w;
        }
        int repU, repV;
        while (n != 1 && edges.size()) {
            w = edges.top().first;
            v = edges.top().second.first;
            u = edges.top().second.second;
            edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV) {
                union_(u, repV);
                ans -= w;
                n--;
            }
        }
        cout << sum_ - ans << "\n";
    }
}

