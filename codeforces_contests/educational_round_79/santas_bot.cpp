#include <bits/stdc++.h>
using namespace std;

int MOD = 998244353;
vector <vector <int>> presents;
vector <int> kids;

int binary_exp(long long a, int b) {
    a %= MOD;
    long long res = 1;
    while (b > 0) {
        if (b&1) res = (res * a ) % MOD;
        a = (a * a ) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    int n, k, in;
    long long ans = 0;
    cin >> n;
    presents.assign(n, vector<int>());
    kids.assign(1000002, 0);
    for (int i = 0; i < n; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> in;
            presents[i].push_back(in);
            kids[in]++;
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int kx = 0; kx < presents[x].size(); ++kx) {
            ans += ((((binary_exp(n, MOD-2) * (binary_exp(presents[x].size(), MOD-2) * 1LL)%MOD) * 1LL * binary_exp(n, MOD-2)) % MOD) *1LL* kids[presents[x][kx]] % MOD);
            ans %= MOD;
        }
    }
    cout << ans << "\n";
}