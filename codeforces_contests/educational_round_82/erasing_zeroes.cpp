#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, ans, flag, c;
    string s;
    cin >> t;
    while (t--){
        ans = 0;
        cin >> s;
        flag = 0;
        c = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                flag = 1;
                ans += c;
                c = 0;
            }else if (flag && s[i] == '0') c++;
        }
        cout << ans << "\n";
    }
    return 0;
}