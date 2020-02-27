#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k, ans, mod;
    cin >> t;
    while (t--){
        cin >> n >> k;
        ans = n/k;
        ans *= k;
        mod = n%k;
        if (mod > (int)k/2){
            ans += (int)k/2;
        }else ans += mod;
        cout << ans << "\n";
    }
    return 0;
}