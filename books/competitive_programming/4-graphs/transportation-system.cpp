//TAG: KRUSKAL
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[1000]; //representantes
int rep_state[1000]; //representantes

int find_state(int x){
    if (rep_state[x] != x){
        rep_state[x] = find_state(rep_state[x]);
    }
    return rep_state[x];
}

void union_state(int x, int y){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep_state[x]){
            rep_state[x] = y;
            break;
        }
        siguiente = rep_state[x];
        rep_state[x] = y;
        x = siguiente;
    }
}

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


vector <pair<double , double>> points;
double dist(int i, int j){
    return sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second)*(points[i].second-points[j].second));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, r, u, v, cs = 1;
    double w, ans_state, ans_rails;
    double x, y;
    cin >> t;
    while (t--){
        points.clear();
        ans_state = ans_rails = 0.0;
        cin >> n >> r;
        for (int i = 0; i <= n; ++i) {
            rep[i] = i;
            rep_state[i] = i;
        }
        priority_queue <pair <double, ii>> edges;
        for (int j = 0; j < n; ++j) {
            cin >> x >> y;
            points.push_back({x,y});
        }
        int state1, state2, states = n;
        for (int l = 0; l < n; ++l) {
            for (int i = l+1; i < n; ++i) {
                double dis = dist(l, i);
                state1 = find_state(l);
                state2 = find_state(i);
                if (dis < r && state1 != state2) {
                    union_state(i, state1);
                    states--;
                }
                edges.push({-dis,{l,i}});
            }
        }
        int repU, repV;
        while (n != 1 && edges.size()){
            w = edges.top().first; v = edges.top().second.first; u = edges.top().second.second; edges.pop();
            repU = find(u);
            repV = find(v);
            state1 = find_state(u);
            state2 = find_state(v);
            if (repU != repV){
                union_(u, repV);
                if (state1 == state2) ans_state -= w;
                else ans_rails -= w;
                n--;
            }
        }
        cout << "Case #" << cs++ <<": " << states << " "  << (int)(ans_state+0.5) << " " << (int)(ans_rails+0.5) << "\n";
    }
    return 0;
}

