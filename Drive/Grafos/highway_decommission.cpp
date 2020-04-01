#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vector <vector<pair<ii, long long>>> g;
vector <ii> mindist;
vi par;
int n;
map <ii, ii> mapeo; //{u, v} --> {d, c}

void dijkstra(int source) {
    par.assign(n+1, -1);
    mindist.assign(n+1, {10000000000000000, 10000000000000000});
    mindist[source] = {0,0};
    priority_queue<pair<ii, long long>, vector<pair<ii, long long>>, greater<pair<ii, long long>>> q; // minheap
    q.push({{0, 0}, source});
    while (!q.empty()) {
        pair<ii, long long> p = q.top(); q.pop();
        int u = p.second; ii dist = p.first; // u = node, dist = mindist from source to u
        if (mindist[u] < dist) continue; // skip outdated improvements
        for (pair<ii,long long>& e : g[u]) {
            int v = e.second; ii w = e.first;
            ii aux = {dist.first + w.first, w.second};
            if (mindist[v] > aux) {
                mindist[v] = aux;
                par[v] = u;
                q.emplace(mindist[v], v);
            }
        }
    }
}


int main(){
    int m, u, v, d, c;
    long long ans = 0;
    cin >> n >> m;
    g.assign(n+1, vector<pair<ii,long long>>());
    for (int j = 0; j < m; ++j) {
        cin >> u >> v >> d >> c;
        if (u > v) swap(u,v);
        if (mapeo.find({u, v}) == mapeo.end())
            mapeo.insert({{u,v},{d,c}});
        else{
            ii e = mapeo.find({u, v})->second;
            e = min(e, {d,c});
            mapeo[{u,v}] = e;
        }
    }
    for (auto ed: mapeo){
        g[ed.first.first].push_back({{ed.second.first, ed.second.second},ed.first.second});
        g[ed.first.second].push_back({{ed.second.first, ed.second.second},ed.first.first});
    }
    dijkstra(1);
    for (int i = 2; i <= n ; ++i) {
        ans += mapeo[{min(i, par[i]), max(i, par[i])}].second;
    }
    cout << ans << "\n";
}