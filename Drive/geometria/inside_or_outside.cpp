//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
vector <int> x;
vector <int> y;

int main() {
    int n, q;
    int xv, yv;
    int flag;
    cin >> n >> q;
    x.reserve(n+1);
    y.reserve(n+1);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    for (int j = 0; j < q; j++) {
        flag = 0;
        cin >> xv >> yv;
        for (int i = 0; i < n; i++) {
            if ((long long int)(x[i+1]-x[i])*(yv-y[i]) < (long long int)(xv-x[i])*(y[i+1]-y[i])){
                cout << "F\n";
                flag = 1;
                break;
            }
        }
        if (!flag){
            cout << "D\n";
        }
    }
}
