#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, n;
    cin >> t;
    while (t--){
        cin >> a >> b >> c >> n;
        if (a < b) swap(a, b);
        if (a < c) swap(a,c);
        n -= (a-b);
        n -= (a-c);
        if (n < 0) cout << "NO\n";
        else{
            if(n%3) cout << "NO\n";
            else cout <<"YES\n";
        }
    }
}