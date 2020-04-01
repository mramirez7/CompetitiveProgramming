//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[2000010]; //representantes
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

vector <pair<long double , long double>> points;
long double dist(int i, int j){
    return sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second)*(points[i].second-points[j].second));
}

int main(){
    int t, n, m, u, v, sensor;
    long double w, ans;
    long double x, y;
    cin >> t;
    while (t--){
        points.clear();
        ans = 0.0;
        cin >> sensor;
        while (1){
            cin >> x;
            if (x < 0.0) break;
            cin >> y;
            points.push_back({x,y});
        }
        n = (int)points.size();
        for (int i = 0; i <= n; ++i)
            rep[i] =  i;
        priority_queue <pair <long double, ii>> edges;
        for (int l = 0; l < n; ++l) {
            for (int i = l+1; i < n; ++i) {
                edges.push({-dist(l, i),{l,i}});
            }
        }
        int repU, repV;
        while (n != sensor && edges.size()){
            w = edges.top().first; v = edges.top().second.first; u = edges.top().second.second; edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV){
                union_(u, repV);
                ans = max(ans, -w);
                n--;
            }
        }
        cout << ceil(ans) << "\n";
    }
    return 0;
}

