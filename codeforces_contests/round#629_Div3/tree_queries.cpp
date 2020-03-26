#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
vi par, vis, h;
vi tree;
vector <ii> q;
vector <pair<int, int>> sparseTable;
vector <pair<int, int>> euler;
vector <int> euler_first;
vector <int> euler_last;
int N;

void dfstree(int u){
    vis[u] = 1;
    euler_first[u] = euler.size();
    euler_last[u] = euler.size();
    euler.push_back({h[u],u});
    for (auto v: g[u]){
        if (vis[v]) continue;
        par[v] = u;
        h[v] = h[u]+1;
        dfstree(v);
        euler_last[u] = euler.size();
        euler.push_back({h[u], u});
    }
}

void buildSparseTable(){
    int log_len_ceil = 32 - __builtin_clz(N);
    sparseTable.reserve(N*log_len_ceil+1);
    int potencias_2 = 2;
    for (int i = 0; i < log_len_ceil; i++) {
        potencias_2 *= 2;
        if (i == 0){
            potencias_2 = 0;
        } else if (i == 1){
            potencias_2 = 1;
        }
        for (int j = 0; j < N; ++j) {
            if (i == 0){
                sparseTable[j] = euler[j];
            } else {
                sparseTable[i*N+j] = min(sparseTable[(i-1)*N + j], sparseTable[(i-1)*N + j + potencias_2]);
            }
            if (j == N - potencias_2){
                break;
            }
        }
    }
}

int query(int i, int j){ //inclusive
    if (i>j) swap(i,j);
    int log_query = 31 - __builtin_clz(j-i+1);
    int largo_query = 1 << log_query;
    if (sparseTable[N*log_query + i].first < sparseTable[N*log_query + j-largo_query+1].first) return sparseTable[N*log_query + i].second;
    return sparseTable[N*log_query + j-largo_query+1].second;
}


int main(){
    int n, m, u, v;
    cin >> n >> m;
    g.assign(n+1, vi());
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.assign(n+1, 0);
    tree.assign(n+1, 0);
    par.assign(n+1, 0);
    h.assign(n+1, 0);
    euler_first.reserve(n+1);
    euler_last.reserve(n+1);
    par[1] = 1;
    h[1] = 0;
    dfstree(1);
    N = euler.size();
    buildSparseTable();
    for (int j = 0; j < m; ++j) {
        q.clear();
        cin >> u;
        for (int i = 0; i < u; ++i) {
            cin >> v;
            q.push_back({h[v], par[v]});
        }
        sort(q.begin(), q.end());
        int flag = 1;
        for (int k = 1; k < q.size(); ++k) {
            int lca = query(min(euler_first[q[k].second], euler_first[q[k-1].second]), max(euler_last[q[k].second], euler_last[q[k-1].second]));
            if (lca != q[k].second && q[k-1].second != lca) {
                flag = 0;
                break;
            }
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
        }
    }
}