#include <bits/stdc++.h>
using namespace std;

int log2(long long x) { return sizeof(x) * 8 - __builtin_clz(x) - 33; }
int p2[61];

int main(){
    int t, m, ans;
    long long n, a, total_sum;
    cin >> t;
    while (t--){
        ans = 0;
        for (int j = 0; j < 61; ++j) p2[j] = 0;
        cin >> n >> m;
        total_sum = 0;
        for (int i = 0; i < m; ++i) {cin >> a; total_sum += a; p2[log2(a)]++;}
        if (n > total_sum){
            cout
            << "-1\n";
            continue;
        }
        for (int k = 0; k < 61; ++k) {
            if (1LL << k & n){
                if (p2[k]) p2[k+1] += (p2[k]-1)/2;
                else{
                    ans++;
                    for (int i = k+1; i < 61; ++i) {
                        if (!p2[i]){
                            ans++;
                            p2[i] = 1;
                        }else {
                            p2[i]--;
                            break;
                        }
                    }
                }
            }else{
                p2[k+1] += p2[k]/2;
            }
        }
        cout << ans << "\n";
    }
}