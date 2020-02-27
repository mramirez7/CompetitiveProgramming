#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, ans, last_angry, local_ans;
    string s;
    cin >> t;
    while (t--){
        ans = 0;
        local_ans = 0;
        last_angry = -1;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A'){
                if (last_angry != -1){
                    ans = max(ans, local_ans);
                }
                last_angry = i;
                local_ans = 0;
            }
            else{
                local_ans++;
            }
        }
        if (last_angry != -1) ans = max(ans,local_ans);
        cout << ans<<"\n";
    }
}