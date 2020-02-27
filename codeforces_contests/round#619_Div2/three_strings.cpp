#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, flag;
    string a, b, c;
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        flag = 1;
        for (int i = 0; i < a.size(); ++i) {
            if (c[i] == a[i] || c[i] == b[i]) continue;
            flag = 0;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}