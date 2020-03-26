#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector <long long> ans;
vector <long long> memo;
long long MOD = 998244353;

long long pow_(int a, int ex){
    if (memo[ex]){
        return memo[ex];
    }
    long long ans = 1;
    for (int i = 0; i < ex; ++i) {
        memo[i] = ans;
        ans *= a;
        ans %= MOD;
    }
    memo[ex] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    ans.reserve(n+1);
    memo.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        int cant_pos = n - i + 1;
        long long mov = 0;
        if (cant_pos == 1)
            mov = 10;
        else {
            long long pw = pow_(10, n-i-1);
            mov += 180*pw;
            mov %=MOD;
            cant_pos -= 2;
            mov += pw*81*cant_pos;
            mov %=MOD;
        }
        ans[i] = mov%MOD;
    }
    for (int j = 1; j <= n ; j++) {
        cout << ans[j] << " ";
    }
}