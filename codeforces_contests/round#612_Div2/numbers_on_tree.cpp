#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <int>> a_numb;
vector <vector <int>> tree;
vector <int> parents;
vector <int> total_childs;
vector <int> ans;
vector <int> c;

int total_child_dfs(int v){
    int ans_ = tree[v].size();
    for (int i = 0; i < tree[v].size(); ++i)
        ans_ += total_child_dfs(tree[v][i]);
    total_childs[v] = ans_;
    return ans_;
}

void a_dfs(int v){
    ans[v] = a_numb[v][c[v]];
    int child = 0;
    for (int i = 0; i < a_numb[v].size(); ++i) {
        if (a_numb[v][i] == ans[v]) continue;
        a_numb[tree[v][child]].push_back(a_numb[v][i]);
        if (a_numb[tree[v][child]].size() == total_childs[tree[v][child]]+1) child++;
    }
    for (int j = 0; j < tree[v].size(); ++j) {
        a_dfs(tree[v][j]);
    }
}

int main(){
    int p, c_, root, flag = 1;
    cin >> n;
    parents.assign(n, 0);
    total_childs.reserve(n+5);
    tree.assign(n, vector <int>());
    for (int i = 0; i < n; ++i) {
        cin >> p >> c_;
        parents[i] = --p;
        c.push_back(c_);
        if (p >= 0) tree[p].push_back(i);
        if (p == -1) root = i;
    }
    total_child_dfs(root);
    for (int j = 0; j < n; ++j)
        if (c[j] > total_childs[j])
            flag = 0;
    if (!flag){
        cout << "NO\n";
        return 0;
    }
    a_numb.assign(n, vector <int>());
    ans.reserve(n+5);
    for (int l = 1; l <= n; ++l) a_numb[root].push_back(l);
    a_dfs(root);
    cout << "YES\n";
    for (int k = 0; k < n; ++k) {
        if (k) cout << " ";
        cout << ans[k];
    }
    cout << "\n";
}