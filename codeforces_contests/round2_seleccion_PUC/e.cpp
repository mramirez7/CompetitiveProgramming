#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, v;
    long long ans;
    cin >> t;
    string s, u;
    while (t--){
        ans = 0;
        v = 0;
        cin >> s;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == s[i+1]) v++;
        }
        ans = v*s.size()*(s.size()-1)/2;
        for (int j = 0; j < s.size()-1; ++j) {
        }
        cout << ans << "\n";
    }
}