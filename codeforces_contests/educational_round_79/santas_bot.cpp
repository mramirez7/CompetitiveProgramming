#include <bits/stdc++.h>
using namespace std;

vector <int> regalos;
map <int, int> mapeo;

int main(){
    int n, m, pr, r = 0, total = 0;
    long long x = 1, y=1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        total += m;
        for (int j = 0; j < m; ++j) {
            cin >> pr;
            if (mapeo.find(pr) == mapeo.end()){
                mapeo.insert({pr, r});
                r++;
                regalos.push_back(1);
            }
            else{
                regalos[mapeo.find(pr)->second]++;
            }
        }
    }
    for (int k = 0; k < regalos.size(); ++k) {
        x *= regalos[k]*regalos[k];
        y *= total*n;
    }
    long long g = __gcd(x,y);
    x /= g;
    y /= g;
    cout << (x*y)%998244353 <<"\n";
}