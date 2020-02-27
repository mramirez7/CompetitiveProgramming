//ACCEPTED
//TAGS: UNION-FIND MST-KRUSKAL
#include <bits/stdc++.h>
using namespace std;

struct city{
    int x, y;
};

int dist(city c1, city c2){
    return (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y);
}

double dist_sqrt(city c1, city c2){
    return sqrt((c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y));
}

vector <city> cities;
int rep[1000];
int rep_mst[1000];
int q[1000];


int find(int x, int rep[1000]){
    if (rep[x] != x){
        rep[x] = find(rep[x], rep);
    }
    return rep[x];
}

void union_(int x, int y, int rep[1000]){
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

int main(){
    int t, case_ = 0, n, r, x, y, rep_1, rep_2;
    int states;
    double roads, railroads;
    cin >> t;
    while (t--) {
        case_++;
        cin >> n >> r;
        states = n; roads = 0; railroads = 0;
        cities.clear();
        for (int j = 0; j < n; ++j) rep[j] = j;
        for (int j = 0; j < n; ++j) q[j] = 1;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            cities.push_back({x,y});
        }
        for (int k = 0; k < n; ++k) {
            rep_1 = find(k, rep);
            for (int i = k+1; i < n; ++i) {
                rep_2 = find(i, rep);
                if (dist(cities[k], cities[i]) <= r*r && rep_1 != rep_2){
                    states--;
                    union_(i, rep_1, rep);
                    q[rep_1] += q[rep_2];
                }
            }
        }
        for (int l = 0; l < n; ++l) rep_mst[l] = l;

        priority_queue <pair <double, pair <int, int>>> edges;
        for (int m = 0; m < n; ++m) {
            for (int i = m+1; i < n; ++i) {
                edges.push({-dist_sqrt(cities[m], cities[i]), {m, i}});
            }
        }

        int repU, repV, u, v;
        double w;
        while (n != 1 && edges.size()){
            w = edges.top().first; v = edges.top().second.first; u = edges.top().second.second; edges.pop();
            repU = find(u, rep_mst);
            repV = find(v, rep_mst);
            if (repU != repV){
                union_(u, repV, rep_mst);
                if (find(v, rep) == find(u, rep)) roads -= w;
                else railroads -= w;
                n--;
            }
        }
        cout << "Case #" << case_ << ": " << states << " " << (int)(roads+0.5) << " " << (int)(railroads+0.5)<< "\n";
    }
}

