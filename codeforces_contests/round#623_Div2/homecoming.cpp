#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, p, changes, ans, ans_ch;
    string s;
    char target;
    cin >> t;
    while (t--){
        cin >> a >> b >> p >> s;
        if (s[s.size()-2] == 'A') s[s.size()-1] = 'B';
        else s[s.size()-1] = 'A';
        changes = 0;
        ans = 1;
        int cost;
        if (s[s.size()-1] == 'A') cost = b;
        else cost = a;
        for (int i = s.size()-2; i >= 0; i--) {
            if (s[i] != s[i+1]) changes++;
        }
        ans_ch = 0;
        while (changes--){
            if (p - cost >= 0){
                p -= cost;
                ans_ch++;
                if (cost == a) cost = b;
                else cost = a;
            } else break;
        }
        for (int i = s.size()-2; i >= 0; i--) {
            if (s[i] != s[i+1]) ans_ch--;
            if (ans_ch < 0){
                ans = i+2;
                break;
            }
        }
        cout << ans << "\n";
    }
}