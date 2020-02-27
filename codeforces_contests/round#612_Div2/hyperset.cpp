#include <bits/stdc++.h>
using namespace std;

string cards[1500];
set <string> st;

int main(){
    int n, k, ans = 0;
    string c;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
        st.insert(cards[i]);
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j+1; i < n; ++i) {
            c = "";
            for (int m = 0; m < k; ++m) {
                if (cards[j][m] == cards[i][m]) c +=cards[j][m];
                else if (cards[j][m] != 'S' && cards[i][m] != 'S') c += 'S';
                else if (cards[j][m] != 'E' && cards[i][m] != 'E') c += 'E';
                else c += 'T';
            }
            if (st.find(c) != st.end()) ans++;
        }
    }
    cout << ans/3 << "\n";
}