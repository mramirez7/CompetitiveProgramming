//TAG: KRUSKAL
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int rep[28]; //representantes
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

int main(){
    int t, n, m, u, v, w, c, cs = 0;
    string r, s;
    cin >> t;
    while (t--){
        cin >> n;
        cs++;
        c = 0;
        for (int i = 0; i < n; ++i)
            rep[i] =  i;
        priority_queue <pair <int, ii>> edges;
        vector <pair <int, ii>> ans;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                cin >> r;
                if (r[r.size()-1] == ',')
                    r = r.substr(0,r.size()-1);
                w = stoi(r);
                if (w && i > j) edges.push({-w,{-j,-i}});
            }
        }
        int repU, repV;
        while (n != 1 && edges.size()){
            w = edges.top().first; v = -edges.top().second.first; u = -edges.top().second.second; edges.pop();
            repU = find(u);
            repV = find(v);
            if (repU != repV){
                union_(u, repV);
                ans.push_back({-w, {v, u}});
                n--;
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << cs << ":\n";
        for (int k = 0; k < ans.size(); ++k) {
            cout << (char)(ans[k].second.first+'A') << "-" << (char)(ans[k].second.second+'A') << " " << ans[k].first << "\n";
        }
    }
    return 0;
}

