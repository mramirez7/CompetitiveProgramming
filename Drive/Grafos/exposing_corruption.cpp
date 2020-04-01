#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int rep[202]; //representantes


vi cost, g;
vi value;
vvi memo;

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
    int d, p, r, b, n, u, v; //cantidad de elementos
    while (cin >> d >> p >> r >> b) {
        n = d + p;
        set<int> reps;
        cost.clear();
        value.clear();
        g.clear();
        for (int i = 0; i < n; i++) {
            rep[i] = i;
            reps.insert(i);
        }
        for (int j = 0; j < n; ++j) {
            cin >> u;
            cost.push_back(u);
            if (j < d) value.push_back(1);
            else value.push_back(-1);
        }
        for (int k = 0; k < r; ++k) {
            cin >> u >> v;
            u--;
            v--;
            v += d;
            int repU = find(u), repV = find(v);
            if (repU != repV) {
                reps.erase(repU);
                cost[repV] += cost[repU];
                value[repV] += value[repU];
                union_(u, repV);
            }
        }
        for (auto a: reps) {
            g.push_back(a);
        }
        memo.assign(reps.size() + 1, vi(b + 1, 0));
        for (int l = reps.size() - 1; l >= 0; l--) {
            for (int i = b; i >= 0; i--) {
                if (cost[g[l]] > i) {
                    memo[l][i] = memo[l + 1][i];
                } else {
                    memo[l][i] = max(memo[l + 1][i], value[g[l]] + memo[l + 1][i - cost[g[l]]]);
                }
            }
        }
        int ans = p + memo[0][b];

        memo.assign(reps.size() + 1, vi(b + 2, 0));
        for (int l = reps.size() - 1; l >= 0; l--) {
            for (int i = b; i >= 0; i--) {
                if (cost[g[l]] > i) {
                    memo[l][i] = memo[l + 1][i];
                } else {
                    memo[l][i] = max(memo[l + 1][i], -1 * value[g[l]] + memo[l + 1][i - cost[g[l]]]);
                }
            }
        }
        cout << d + abs(memo[0][b]) << " " << ans << "\n";
    }
}