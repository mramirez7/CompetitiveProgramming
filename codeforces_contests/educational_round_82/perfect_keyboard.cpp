#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;
vector <set <char>> g;

int main(){
    int t, flag, first;
    string s, ans;
    cin >> t;
    while (t--) {
        visited.assign(26, false);
        g.assign(26, set <char>());
        ans = "";
        flag = 1;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) visited[s[i]-'a'] = 1;
        for (int j = 0; j < s.size(); ++j) {
            if (j) g[s[j] - 'a'].insert(s[j-1]);
            if (j+1 < s.size()) g[s[j] - 'a'].insert(s[j+1]);
        }
        first = -1;
        for (int k = 0; k < 26; ++k) {
            if (g[k].size() == 0) ans += (char)(k+'a');
            else if (g[k].size() == 1) first = k;
            else if (g[k].size() >= 3) flag = 0;
        }
        if (first == -1 && ans.size() != 26) flag = 0;
        if (!flag){ cout << "NO\n";
            continue; }
        while (ans.size() != 26){
            ans += (char)(first + 'a');
            auto it = g[first].begin();
            if (*it != ans[ans.size()-2]) first = *it - 'a';
            else it++, first = *it - 'a';
        }
        cout << "YES\n" << ans << "\n";
    }
}