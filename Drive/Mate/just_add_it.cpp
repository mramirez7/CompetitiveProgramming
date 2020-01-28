#include <bits/stdc++.h>
using namespace std;

long m = 10000007;
long long binary_exp(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b&1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main(){
    long long n, k, ans;
    while (cin >> n >> k){
        if (!(n|k))return 0;
        ans = 0;
        ans += binary_exp(n, k);
        ans += binary_exp(n, n);
        ans += 2*binary_exp(n-1, k);
        ans += 2*binary_exp(n-1, n-1);
        cout << ans%m << "\n";
    }
}


