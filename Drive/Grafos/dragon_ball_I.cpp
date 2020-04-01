#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vector <vector<ii>> g;
vvi mindist;
vi par;
set <int> balls;
int n, balldist[8][8];


void dijkstra(int source) {
    par.assign(n+1, -1);
    mindist[source].assign(n+1, INT_MAX);
    mindist[source][source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q; // minheap
    q.emplace(0, source);
    while (!q.empty()) {
        ii p = q.top(); q.pop();
        int u = p.second, dist = p.first; // u = node, dist = mindist from source to u
        if (mindist[source][u] < dist) continue; // skip outdated improvements
        for (ii& e : g[u]) {
            int v = e.second, w = e.first;
            if (mindist[source][v] > dist + w) {
                mindist[source][v] = dist + w;
                par[v] = u;
                q.emplace(mindist[source][v], v);
            }
        }
    }
}

long long dfs(string u, set<int> st){
    long long ans = 10000000000;
    if (st.size() == 0){
        ans = 0;
        for (int i = 1; i < balls.size(); ++i) {
            ans += balldist[u[i-1]-'0'][u[i]-'0'];
        }
        return ans;
    }
    set <int> stcpy;
    for (auto a: st) stcpy.insert(a);
    for (auto v: st) {
        string s = u;
        s += (v+'0');
        stcpy.erase(v);
        ans = min(ans, dfs(s, stcpy));
        stcpy.insert(v);
    }
    return ans;
}


int main(){
    int m, u, v, w;
    cin >> n >> m;
    g.assign(n+1, vector<ii>());
    for (int j = 0; j < m; ++j) {
        cin >> u >> v >> w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    mindist.assign(n+1, vi());
    for (int i = 0; i < 7; ++i) {
        cin >> u;
        balls.insert(u);
    }
    balls.insert(1);
    int c1 = 0, c2;
    for (auto b: balls){
        dijkstra(b);
        c2 = 0;
        for (auto aa: balls) {
            balldist[c1][c2++] = mindist[b][aa];
        }
        c1++;
    }
    set <int> per;
    for (int k = 1; k < balls.size(); ++k) {
        per.insert(k);
    }
    cout << dfs("0", per);
}