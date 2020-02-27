#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, b, flag;
    cin >> t;
    while (t--){
        flag = 1;
        cin >> n;
        set <int> st;
        vector <int> bs;
        for (int j = 1; j <= 2*n; ++j) st.insert(j);
        for (int i = 0; i < n; ++i) {
            cin >> b;
            bs.push_back(b);
            bs.push_back(0);
            st.erase(b);
        }
        for (int k = 0; k < bs.size(); k+=2) {
            if (st.upper_bound(bs[k]) == st.end()) flag = 0;
            else {
                bs[k+1] = *st.upper_bound(bs[k]);
                st.erase(*st.upper_bound(bs[k]));
            }
        }
        if (flag) {
            for (int l = 0; l < bs.size(); ++l) {
                cout << bs[l] << " ";
            }
            cout << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}