//ACCEPTED
//TAGS: EULER TOUR + SPARSE TABLE
#include <bits/stdc++.h>
using namespace std;

vector <int> parent;
vector <vector<int>> adj;
vector <pair<int, int>> euler;
vector <int> euler_first;
vector <int> euler_last;
vector <int> height;
vector <pair<int, int>> sparseTable;
int N;

void dfs(int u, int h){
    height[u] = h;
    euler_first[u] = euler.size();
    euler_last[u] = euler.size();
    euler.push_back({h,u});
    for (int i = 0; i < adj[u].size(); ++i) {
        dfs(adj[u][i], h+1);
        euler_last[u] = euler.size();
        euler.push_back({h, u});
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

int query(int i, int j){ //inclusive
    if (i>j) swap(i,j);
    int log_query = 31 - __builtin_clz(j-i+1);
    int largo_query = 1 << log_query;
    if (sparseTable[N*log_query + i].first < sparseTable[N*log_query + j-largo_query+1].first) return sparseTable[N*log_query + i].second;
    return sparseTable[N*log_query + j-largo_query+1].second;
}


int main(){
    int t, n, m, u, root, q, q1, q2, case_n = 0;
    cin >> t;
    while (t--){
        case_n++;
        adj.clear();
        euler.clear();
        euler_first.clear();
        euler_last.clear();
        cin >> n;
        euler_first.reserve(n);
        euler_last.reserve(n);
        height.reserve(n);
        parent.assign(n, -1);
        adj.assign(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            cin >> m;
            for (int j = 0; j < m; ++j) {
                cin >> u; u--;
                adj[i].push_back(u);
                parent[u] = i;
            }
        }
        root = 0;
        while (parent[root] != -1) root = parent[root];
        dfs(root, 0);
        N = euler.size();
        builldSparseTable();
        cin >> q;
        cout << "Case " << case_n <<":\n";
        for (int k = 0; k < q; ++k) {
            cin >> q1 >> q2;
            q1--; q2--;
            cout << 1+query(min(euler_first[q1], euler_first[q2]), max(euler_last[q1], euler_last[q2])) << "\n";
        }
    }
}

