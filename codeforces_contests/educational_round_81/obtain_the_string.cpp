#include <bits/stdc++.h>
using namespace std;

int nxt[100010][26];
int inf = INT_MAX/4;

int main(){
    int T, p, ans, t_pointer;
    string s, t;
    cin >> T;
    while (T--){
        cin >> s >> t;
        ans = 0; t_pointer = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                nxt[i][j] = inf;
            }
        }
        p = (int)(s[s.size()-1] - 'a');
        for (int k = s.size()-2; k >= 0 ; k--) {
            for (int i = 0; i < 26; ++i) {
                if (i == p) nxt[k][i] = k+1;
                else nxt[k][i] = nxt[k+1][i];
            }
            p = (int)(s[k]-'a');
        }
        for (int l = 0; l < t.size(); ++l) {
            if (nxt[0][t[l]-'a'] == inf && t[l] != s[0])
                ans = -1;
        }
        if (ans == -1){ cout << ans << "\n"; continue; }
        while (t_pointer < t.size()){
            if (t[t_pointer] == s[0]) p = 0;
            else p = nxt[0][t[t_pointer]-'a'];
            t_pointer++;
            if (p == inf) t_pointer++;
            while (p != inf && t_pointer < t.size()) p = nxt[p][t[t_pointer++]-'a'];
            if (p == inf) t_pointer--;
            ans++;
        }
        cout << ans << "\n";
    }
}