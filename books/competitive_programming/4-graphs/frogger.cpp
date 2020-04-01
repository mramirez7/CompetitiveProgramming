//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[202]; //representantes
vector <vector<pair<double, int>>> g;

int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}

struct Point {int x, y;};
vector <Point> points;
vi vis;
long double dist(int i, int j){
    return sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x) + (points[i].y-points[j].y)*(points[i].y-points[j].y));
}

double ans = 0.0;

bool dfs(int u){
    vis[u] = 1;
    if (g[u].size() == 1 && u || u == 1){
        if (u == 1)
            return true;
        else
            return false;
    }
    for (auto v: g[u]){
        if (vis[v.second]) continue;
        if (dfs(v.second)){
            ans = max(ans, v.first);
            return true;
        }
    }
    return false;
}

int main(){
    cout<<setprecision(3)<<fixed;
    int n, u, v, cs = 1;
    double w;
    while (1) {
        cin >> n;
        ans = 0.0;
        if (!n) break;
        points.clear();
        vis.assign(n,0);
        points.reserve(n);
        g.clear();
        g.assign(n, vector<pair<double,int>>());
        for (int i = 0; i <= n; ++i)
            rep[i] = i;
        priority_queue <pair<double, ii>> edges;
        for (int j = 0; j < n; ++j) {
            cin >> u >> v;
            points[j].x = u;
            points[j].y = v;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = k+1; i < n; ++i) {
                edges.push({-dist(k,i), {k, i}});
            }
        }
        int repU, repV;
        while (n != 1 && edges.size()) {
            w = edges.top().first;
            v = edges.top().second.first;
            u = edges.top().second.second;
            edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV) {
                union_(u, repV);
                g[u].push_back({-w,v});
                g[v].push_back({-w,u});
                n--;
            }
        }
        dfs(0);
        cout << "Scenario #" << cs++ << "\n";
        cout << "Frog Distance = " << ans << "\n\n";
    }
}

