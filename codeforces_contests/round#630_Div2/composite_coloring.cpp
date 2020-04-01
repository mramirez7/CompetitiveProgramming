#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vi numb, primes = {2,3,5,7,11,13,17,19,23,29,31}, ans;
vvi col;
map <int,int> mapeo;

int main(){
    int t, n, u, v;
    cin >> t;
    while (t--){
        cin >> n;
        numb.clear();
        mapeo.clear();
        ans.assign(n, 0);
        for (int i1 = 0; i1 < n; ++i1) {
            cin >> u;
            numb.push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 11; ++j) {
                if (numb[i]%primes[j] == 0){
                    ans[i] = j+1;
                }
            }
        }
        int colores = 0;
        for (int k = 0; k < n; ++k) {
            if (mapeo.find(ans[k]) == mapeo.end())
                mapeo[ans[k]] = ++colores;
        }
        cout << colores << "\n";
        for (int l = 0; l < n; ++l) {
            cout << mapeo[ans[l]] << " ";
        }
        cout << "\n";
    }
}