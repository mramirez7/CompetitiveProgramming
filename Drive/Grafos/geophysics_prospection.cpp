//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> graph;
vector<vector<vector<bool>>> visited;

vector <int> a;
vector <int> b;
vector <int> c;
vector <int> d;

int n, m, w;

bool isValid(int p, int i,int  j){
    if (p >= 0 && p < w && i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}

int dfs(int w, int i,int  j){
    visited[w][i][j] = true;
    int ans = 1;
    if (isValid(w-1, i, j) && !visited[w-1][i][j] && graph[w][i][j] == graph[w-1][i][j]) ans += dfs(w-1,i,j);
    if (isValid(w+1, i, j) && !visited[w+1][i][j] && graph[w][i][j] == graph[w+1][i][j]) ans += dfs(w+1,i,j);
    if (isValid(w, i-1, j) && !visited[w][i-1][j] && graph[w][i][j] == graph[w][i-1][j]) ans += dfs(w,i-1,j);
    if (isValid(w, i+1, j) && !visited[w][i+1][j] && graph[w][i][j] == graph[w][i+1][j]) ans += dfs(w,i+1,j);
    if (isValid(w, i, j-1) && !visited[w][i][j-1] && graph[w][i][j] == graph[w][i][j-1]) ans += dfs(w,i,j-1);
    if (isValid(w, i, j+1) && !visited[w][i][j+1] && graph[w][i][j] == graph[w][i][j+1]) ans += dfs(w,i,j+1);
    return ans;
}

int main(){
    int case_ = 0;
    string line;
    while (cin >> n >> m >> w) {
        if (case_) cout << "\n";
        case_++;
        a.clear();
        b.clear();
        c.clear();
        d.clear();
        graph.assign(n, vector<string>());
        visited.assign(w, vector < vector < bool >> ());
        for (int k = 0; k < w; ++k) {
            visited[k].assign(n, vector<bool>());
            for (int i = 0; i < n; ++i) {
                visited[k][i].assign(m, 0);
            }
        }
        for (int i = 0; i < w; ++i) {
            graph[i].clear();
            for (int j = 0; j < n; ++j) {
                cin >> line;
                graph[i].push_back(line);
            }
        }
        for (int l = 0; l < w; ++l) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!visited[l][i][j]) {
                        if (graph[l][i][j] == 'a') a.push_back(dfs(l, i, j));
                        if (graph[l][i][j] == 'b') b.push_back(dfs(l, i, j));
                        if (graph[l][i][j] == 'c') c.push_back(dfs(l, i, j));
                        if (graph[l][i][j] == 'd') d.push_back(dfs(l, i, j));
                    }
                }
            }
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());

        cout << "Case " << case_ << ":\na ";
        if (!a.size()) cout << "0\nb ";
        else{
            for (int i1 = 0; i1 < a.size(); ++i1) {
                cout << a[i1];
                if (i1 != a.size() - 1) cout << " ";
                else cout << "\nb ";
            }
        }
        if (!b.size()) cout << "0\nc ";
        else{
            for (int i1 = 0; i1 < b.size(); ++i1) {
                cout << b[i1];
                if (i1 != b.size() - 1) cout << " ";
                else cout << "\nc ";
            }
        }
        if (!c.size()) cout << "0\nd ";
        else{
            for (int i1 = 0; i1 < c.size(); ++i1) {
                cout << c[i1];
                if (i1 != c.size() - 1) cout << " ";
                else cout << "\nd ";
            }
        }
        if (!d.size()) cout << "0\n";
        else{
            for (int i1 = 0; i1 < d.size(); ++i1) {
                cout << d[i1];
                if (i1 != d.size() - 1) cout << " ";
                else cout << "\n";
            }
        }
    }
}

