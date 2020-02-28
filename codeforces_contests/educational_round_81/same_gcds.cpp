#include <bits/stdc++.h>
using namespace std;

void phi(long long x){
    long long ans = x;
    for (long long i = 2; i*i <= x; ++i) {
        if (x % i == 0){
            ans -= ans/i;
            while (x%i == 0) x /= i;
        }
    }
    if (x-1) ans -= ans/x;
    cout << ans << "\n";
}

int main(){
    int t;
    long long a, m, g, mm;
    cin >> t;
    while (t--){
        cin >> a >> m;
        g = __gcd(a, m);
        phi(m/g);
    }
}