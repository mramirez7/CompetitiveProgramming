//ACCEPTED
//TAG: TOPOLOGICAL SORT GREEDY
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;

vector<set <int>> g;
vector<vi> gr;
map <string, int> mapeo;
map <int, string> mapeo_inv;
vi ans;

int main(){
    int n, m, cases = 0;
    string s, t;
    while (cin >> n) {
        cases++;
        ans.clear();
        g.clear();
        gr.clear();
        g.assign(n, set<int>());
        gr.assign(n, vi());
        mapeo_inv.clear();
        mapeo.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s;
            mapeo.insert({s, i});
            mapeo_inv.insert({i, s});
        }
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> s >> t;
            if (g[mapeo.find(t)->second].find(mapeo.find(s)->second) == g[mapeo.find(t)->second].end()) {
                g[mapeo.find(t)->second].insert(mapeo.find(s)->second);
                gr[mapeo.find(s)->second].push_back(mapeo.find(t)->second);
            }
        }
        priority_queue <int> pq;
        for (int k = 0; k < n; ++k) {
            if (g[k].size() == 0)
                pq.push(-k);
        }
        while (pq.size()){
            int v = -pq.top(); pq.pop();
            ans.push_back(v);
            for (auto u: gr[v]){
                g[u].erase(v);
                if (g[u].size() == 0) pq.push(-u);
            }
        }
        cout << "Case #" << cases << ": Dilbert should drink beverages in this order:";
        for (int l = 0; l < ans.size(); ++l) {
            cout << " " << mapeo_inv.find(ans[l])->second;
        }
        cout << ".\n\n";
    }
}