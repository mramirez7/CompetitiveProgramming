#include <bits/stdc++.h>
using namespace std;

long long c2 (long long x){
    return x*(x+1)/2;
}

int main(){
    int t;
    long long n, m, ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (m) {
            ans = c2(n);
            ans -= c2((n - m) / (m+1)) * ((m+1) - (n-m)%(m+1));
            ans -= c2((n - m) / (m+1)+1) * ((n-m)%(m+1));
        } else ans = 0;
        cout << ans << "\n";
    }
}