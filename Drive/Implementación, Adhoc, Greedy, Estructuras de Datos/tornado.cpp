//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

vector <int> postes;

int main(){
    int n, ans, ind, cont, flag;
    postes.reserve(5000);
    while (cin >> n){
        ind = 5001;
        flag= 0;
        if (!n) return 0;
        cont = 0;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> postes[i];
            if (postes[i]) ind = min(ind, i);
        }
        if (ind == 5001) ans = (n+1)/2;
        else {
            for (int i = ind; i < ind+n; ++i) {
                if (postes[i%n]) cont = 0;
                else cont++;
                if (cont == 2){
                    ans++;
                    cont = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}
