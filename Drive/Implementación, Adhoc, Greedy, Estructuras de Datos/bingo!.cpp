//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, b, m, numb[91], is_possible[91];
    while (1){
        cin >> n >> b;
        if (!(n+b)) break;
        for (int i = 0; i <= n; i++) {
            numb[i] = 0;
            is_possible[i] = 0;
        }
        for (int j = 0; j < b; j++) {
            cin >> m;
            numb[m] = 1;
        }
        for (int k = 0; k <= n; k++) {
            if (!numb[k]) continue;
            for (int i = k+1; i <= n; i++) {
                if (!numb[i]) continue;
                is_possible[i-k] = 1;
            }
        }
        int ans = 1;
        for (int l = 1; l <= n; ++l) {
            ans = ans*is_possible[l];
        }
        if (ans) cout << "Y\n";
        else cout << "N\n";
    }
}