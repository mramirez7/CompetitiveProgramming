//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[760]; //representantes
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
vector <ii> ans;
long double dist(int i, int j){
    return sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x) + (points[i].y-points[j].y)*(points[i].y-points[j].y));
}

int main(){
    cout<<setprecision(3)<<fixed;
    int t, n, m, u, v, cs = 0;
    double w;
    cin >> t;
    while (t--) {
        if (cs++) cout << "\n";
        cin >> n;
        ans.clear();
        points.clear();
        vis.assign(n+1,0);
        points.reserve(n+1);
        for (int i = 0; i <= n; ++i)
            rep[i] = i;
        priority_queue <pair<double, ii>> edges;
        for (int j = 1; j <= n; ++j) {
            cin >> u >> v;
            points[j].x = u;
            points[j].y = v;
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = k+1; i <= n; ++i) {
                edges.push({-dist(k,i), {k, i}});
            }
        }
        cin >> m;
        int repU, repV;
        for (int l = 0; l < m; ++l) {
            cin >> u >> v;
            repU = find(u);
            repV = find(v);
            if (repU != repV) union_(u, repV);
        }
        while (n != 1 && edges.size()) {
            w = edges.top().first;
            v = edges.top().second.first;
            u = edges.top().second.second;
            edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV) {
                union_(u, repV);
                ans.push_back({v, u});
                n--;
            }
        }
        if (ans.size()){
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
        }
        else cout << "No new highways need\n";
    }
}

