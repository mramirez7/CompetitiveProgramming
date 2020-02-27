#include <bits/stdc++.h>
using namespace std;

int tried[200010];
int memo[200010][26];
int ans[26];

int main(){
    int t, n, m;
    string combo;
    cin >> t;
    while (t--){
        for (int j = 0; j < 26; ++j) ans[j] = 0;
        cin >> n >> m;
        cin >> combo;
        for (int k = 0; k < n; ++k)
            for (int l = 0; l < 26; ++l) {
                memo[k][l] = 0;
            }
        for (int i = 0; i < m; ++i) {
            cin >> tried[i];
        }
        memo[0][combo[0]-'a'] = 1;
        for (int i1 = 1; i1 < n; ++i1) {
            for (int i = 0; i < 26; ++i) {
                memo[i1][i] = memo[i1-1][i];
            }
            memo[i1][combo[i1]-'a']++;
        }
        sort(tried, tried+m);
        for (int j1 = 0; j1 < m; ++j1) {
            for (int i = 0; i < 26; ++i) {
                ans[i] += memo[tried[j1]-1][i];
            }
        }
        for (int k1 = 0; k1 < n; ++k1) {
            ans[combo[k1]-'a']++;
        }
        for (int l1 = 0; l1 < 26; ++l1) {
            cout << ans[l1] << " ";
        }
        cout << "\n";
    }
    return 0;
}