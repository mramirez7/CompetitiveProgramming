#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, a;
    long long ans = 0;
    cin >> n >> m >> a;
    if (!(n%a)) ans += n/a;
    else ans += 1+n/a;
    if (!(m%a)) ans *= (m/a);
    else ans *= (1+(m/a));
    cout << ans << "\n";
    return 0;
}