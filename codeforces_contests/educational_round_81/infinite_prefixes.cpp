#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, delta;
    long long x, ans;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        cin >> s;
        delta = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') delta++;
            else delta--;
        }
        if (!delta){
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') delta++;
                else delta--;
                if (delta == x) ans = -1;
            }
            cout << ans << "\n";
        } else {
            int bal = 0;
            for (int i = 0; i < n; ++i) {
                if ((x-bal)%delta == 0 && (x-bal)/delta >= 0) ans++;
                if (s[i] == '0') bal++;
                else bal--;
            }
            cout << ans << "\n";
        }
    }
}