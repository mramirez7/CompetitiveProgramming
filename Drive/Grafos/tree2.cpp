//ACCEPTED
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> g;
vector <int> tree1;
vector <int> level1;
vector <int> tree2;
vector <int> level2;
vector <int> diametro_ordenado;
vector <ii> memo;
vector <vector<int>> st1;
vector <vector<int>> st2;

int n, d1, d2, a, d, n_diam;

int bfs(int v){
    vector <int> vis(n+1,0);
    vis[v] = 1;
    queue <int> q;
    q.push(v);
    int u;
    while (q.size()){
        u = q.front(); q.pop();
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); ++i) {
            if (!vis[g[u][i]]) q.push(g[u][i]);
        }
    }
    return u;
}

void tree_generator(int v, vector<int>& t, vector<int>& l){
    vector <int> vis(n+1,0);
    queue <ii> q;
    q.push({v, 0});
    t[v] = v;
    l[v] = 0;
    ii u;
    while (q.size()){
        u = q.front(); q.pop();
        vis[u.first] = 1;
        for (int i = 0; i < g[u.first].size(); ++i) {
            if (!vis[g[u.first][i]]) {
                q.push({g[u.first][i], u.second+1});
                t[g[u.first][i]] = u.first;
                l[g[u.first][i]] = u.second + 1;
            }
        }
    }
}

int ans(int x){
    if (x == 1 && level1[a] < d) return 0;
    else if (x==1) return diametro_ordenado[level1[a]-d];
    if (x == 2 && level2[a] < d) return 0;
    else if (x==2) return diametro_ordenado[n_diam - 1 - level2[a]+d];
}

ii distancia_a_diametro(int p){
    if (memo[p].first != -1){
        return memo[p];
    }
    else if (memo[tree2[p]].first != -1){
        memo[p] = memo[tree2[p]];
        memo[p].first++;
        return memo[p];
    }
    distancia_a_diametro(tree2[p]);
    memo[p] = memo[tree2[p]];
    memo[p].first++;
    return memo[p];
}

void st_generator(int d, vector<vector<int>>& st, vector<int>& p){
    st[d][0] = p[d];
    for (int i = 1; i <= 15; i++){
        st[d][i] = st[st[d][i-1]][i-1];
    }
    for (int j = 0; j < g[d].size(); ++j) {
        if (g[d][j] != p[d])
            st_generator(g[d][j], st, p);
    }
}

int ans2(int v, int d){
    if (!d) return v;
    for (int i = 0; i <= 15; ++i) {
        if (d & (1 << i)){
            return ans2(st2[v][i],d - (1<<i));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q, u, v;
    cin >> n >> q;
    g.assign(n+1, vector<int>());
    tree1.assign(n+1,0);
    tree2.assign(n+1,0);
    level1.assign(n+1,0);
    level2.assign(n+1,0);
    memo.assign(n+1, {-1, 0});
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d1 = bfs(1);
    d2 = bfs(d1);
    tree_generator(d1,tree1,level1);
    tree_generator(d2,tree2,level2);
    st1.assign(n+1, vector<int>(15, d1));
    st2.assign(n+1, vector<int>(15, d2));
    st_generator(d1, st1, tree1);
    st_generator(d2, st2, tree2);
    set <int> diametro;
    u  = d1;
    for (int j = 1; j <= n ; ++j) {
        diametro.insert(u);
        diametro_ordenado.push_back(u);
        memo[u] = {0,u};
        if (u == tree2[u]) break;
        u = tree2[u];
    }
    n_diam = diametro.size();
    for (int k = 0; k < q; ++k) {
        cin >> a >> d;
        int b, e;
        b = distancia_a_diametro(a).second;
        e = d-distancia_a_diametro(a).first;
        if (e < 0) {
            a = ans2(a, d);
            d = 0;
        }
        else {a = b; d = e;}
        if (!d) cout << a << "\n";
        else if (level1[a] > level2[a])
            cout << ans(1) << "\n";
        else cout << ans(2) << "\n";
    }
}