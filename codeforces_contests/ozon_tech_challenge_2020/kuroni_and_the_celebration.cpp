#include <bits/stdc++.h>
using namespace std;

vector <set <int>> tree;
vector <int> dead;

int main() {
    int n,u,v, sze;
    queue <int> leaves;
    cin >> n;
    sze = n;
    tree.assign(n+1, set<int>());
    dead.assign(n+1, 0);
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        tree[u].insert(v);
        tree[v].insert(u);
    }
    for (int j = 1; j <= n; ++j) {
        if (tree[j].size() == 1) leaves.push(j);
    }
    int q1, q2, lca;
    while (1){
        q1 = leaves.front(); leaves.pop();
        q2 = leaves.front(); leaves.pop();
        cout << "? " << q1 << " " << q2 << "\n";
        cout << flush;
        cin >> lca;
        if (lca == q1 || lca == q2){
            cout << "! " << lca << "\n";
            return 0;
        }
        dead[q1] = 1;
        dead[q2] = 1;
        sze -= 2;
        if (sze == 1){
            for (int i = 1; i <= n ; ++i) {
                if (!dead[i]) {
                    cout << "! " << i << "\n";
                    return 0;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (dead[i]) continue;
            if (tree[i].find(q1) != tree[i].end()){
                tree[i].erase(q1);
                if (tree[i].size() == 1){
                    leaves.push(i);
                }
            }
            if (tree[i].find(q2) != tree[i].end()){
                tree[i].erase(q2);
                if (tree[i].size() == 1){
                    leaves.push(i);
                }
            }
        }
    }
}