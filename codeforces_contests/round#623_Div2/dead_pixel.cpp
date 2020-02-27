#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, x, y, x_ans, y_ans, ans;
    cin >> t;
    while (t--){
        cin >> a >> b >> x >> y;
        ans = x*b;
        ans = max(ans, (a-x-1)*b);
        ans = max(ans, y*a);
        ans = max(ans, (b-y-1)*a);
        cout << ans << "\n";
    }
    return 0;
}