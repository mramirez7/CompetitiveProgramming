//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, ans, c;
    while (cin >> t){
        ans = 0;
        for (int i = 0; i < 5; i++) {
            cin >> c;
            if (c == t) ans++;
        }
        cout << ans << "\n";
    }
}