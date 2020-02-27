#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long n, d, flag, r, last;
    cin >> t;
    while (t--){
        cin >> n >> d;
        flag = 0;
        if (n >= d) cout << "YES\n";
        else{
            last = 0;
            for (int x = 0; x < n; ++x) {
                r = d%(x+1);
                if (r) r = 1;
                if (x + r + d/(x+1) <= n){
                    flag = 1;
                    break;
                }
                if (r + d/(x+1) == last) {
                    break;
                }
                last = r + d/(x+1);
            }
            if (flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}