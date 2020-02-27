#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long a, b, ans, p10;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        p10 = 10;
        ans = 0;
        while (1){
            if (b >= p10-1) ans++;
            else break;
            p10 *= 10;
        }
        cout << a*ans << "\n";
    }
}