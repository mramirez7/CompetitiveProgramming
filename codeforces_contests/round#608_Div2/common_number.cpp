#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long count(long long m){
    long long ans = m%2 - 1;
    m = m%2 == 0 ? m/2 : m;
    long long inf = m, sup = m;
    while (1){
        if (inf > n) break;
        else if (sup > n) ans += 1+n-inf;
        else ans += 1+sup-inf;
        inf = 2*inf;
        sup = 2*sup+1;
    }
    return ans;
}

int main(){
    cin >> n >> k;
    long long inf, sup, bin, ans = 1;
    inf = 1; sup = n/2;
    while (sup >= inf){
        bin = (sup+inf)/2;
        if (count(2*bin) < k) sup = bin-1;
        else {
            ans = 2*bin;
            inf = bin+1;
        }
    }
    inf = 1; sup = n/2;
    while (sup >= inf){
        bin = (sup+inf)/2;
        if (count(2*bin+1) < k) sup = bin-1;
        else {
            ans = max(ans, 2*bin+1);
            inf = bin+1;
        }
    }
    cout << ans << "\n";
}