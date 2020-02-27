#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0, mod, reserva;
    while (cin >> n >> k){
        ans = n;
        while (n >= k){
            mod = n%k;
            reserva = n/k;
            n = reserva+mod;
            ans += reserva;
        }
        cout << ans << "\n";
    }
}