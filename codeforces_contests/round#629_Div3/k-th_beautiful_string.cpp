#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int main(){
    int t, n, k;
    long long piso, inf, sup, bin;
    cin >> t;
    while (t--){
        piso = 0;
        cin >> n >> k;
        long long cont = 1;
        while (cont*(cont+1)/2 < k) cont++;
        long long pp = k - cont*(cont-1)/2 - 1;
        for (int i = n-1; i >= 0 ; i--) {
            if (i == cont || i == pp)
                cout << "b";
            else cout << "a";
        }
        cout << "\n";

    }
}