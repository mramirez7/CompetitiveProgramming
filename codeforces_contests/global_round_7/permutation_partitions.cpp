#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
long long MOD = 998244353;

int main(){
    long long n, k, aux;
    long long ans_sum;
    long long posibilities = 1;
    cin >> n >> k;
    ans_sum = (n*(n+1)/2) - ((n-k)*(n-k+1)/2);
    int acum = 1, flag = 0;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        if (aux > n - k){
            if (flag) {
                posibilities *= acum;
                posibilities %= MOD;
            }
            acum = 1;
            flag = 1;
        }else acum++;
    }
    cout << ans_sum << " " << posibilities << "\n";
}