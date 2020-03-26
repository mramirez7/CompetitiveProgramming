#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector <int> pr;
vector <int> vis;
vector <priority_queue<int>> g;


int main(){
    int t, n, c, cand;
    cin >> t;
    while (t--){
        cin >> n;
        g.clear();
        pr.clear();
        vis.clear();
        pr.assign(n+1,0);
        vis.assign(n+1,0);
        g.assign(n+1, priority_queue<int>());
        for (int i = 1; i <= n; ++i) {
            cin >> c;
            for (int j = 0; j < c; ++j) {
                cin >> cand;
                pr[cand]++;
                g[i].push(-cand);
            }
        }
        int flag = 0;
        int l;
        for (l = 1; l <= n; ++l) {
            while (g[l].size() && vis[-g[l].top()]) g[l].pop();
            if (!g[l].size()){
                if (!flag) flag = l;
                continue;
            }
            vis[-g[l].top()] = 1;
        }
        if (!flag) cout << "OPTIMAL\n";
        else{
            cout << "IMPROVE\n";
            cout << flag << " ";
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]){
                    cout << i << "\n";
                    break;
                }

            }
        }
    }
}