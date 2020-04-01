typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

//BINARY LIFTING
int st[20000][15]; //st[V][log2(V)]
int p[20000]; //parent
void st_generator(int d, vector<vector<int>>& st){ //se llama desde la raiz
    st[d][0] = p[d];
    for (int i = 1; i <= 15; i++){
        st[d][i] = st[st[d][i-1]][i-1];
    }
    for (int j = 0; j < g[d].size(); ++j) {
        if (g[d][j] != p[d])
            st_generator(g[d][j], st, p);
    }
}

int query(int v, int d){ //encuentra un ancestro a distancia d
    if (!d) return v;
    for (int i = 0; i <= 15; ++i) { //cambiar 15 por (log2(V))
        if (d & (1 << i)){
            return query(st2[v][i],d - (1<<i));
        }
    }
}


// EULER TOUR + SPARSE TABLE
#include <bits/stdc++.h>
using namespace std;

vi par;
vvi g;
vecotr <ii> euler;
vi euler_f;
vi euler_l;
vi h, vis;
vector <ii> sparseTable;
int N;

void dfs(int u){
    vis[u] = 1;
    h[u] = h[par[u]]+1;
    euler_f[u] = euler.size();
    euler_l[u] = euler.size();
    euler.push_back({h[u],u});
    for (int i = 0; i < g[u].size(); ++i) {
        if (vis[g[u][i]]) continue;
        dfs(g[u][i]);
        euler_last[u] = euler.size();
        euler.push_back({h[u], u});
    }
}

void builldSparseTable(){
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

int query_(int i, int j){ //inclusive
    if (i>j) swap(i,j);
    int log_query = 31 - __builtin_clz(j-i+1);
    int largo_query = 1 << log_query;
    if (sparseTable[N*log_query + i].first < sparseTable[N*log_query + j-largo_query+1].first) return sparseTable[N*log_query + i].second;
    return sparseTable[N*log_query + j-largo_query+1].second;
}

int query(int u, int v) {
    return query_(query(min(euler_first[u], euler_first[v]), max(euler_last[u], euler_last[v])));
}



int main(){
    int t, n, m, u, root, q, q1, q2;
    cin >> n;
    euler_first.reserve(n);
    euler_last.reserve(n);
    h.reserve(n);
    h[0] = -1; //cambiar por root
    par.assign(n, -1);
    par[0] = 0; //cambiar por root
    g.assign(n, vector<int>());
    //leer grafo
    dfs(0); //cambiar por root
    N = euler.size();
    builldSparseTable();
    //query(v, u)
}

