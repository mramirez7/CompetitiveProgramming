#include <bits/stdc++.h>
using namespace std;

string cards[1500];

int main(){
    int n, k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j+1; i < n; ++i) {
            for (int l = i+1; l < n; ++l) {
                for (int m = 0; m < k; ++m) {
                    if ((cards[j][m] == cards[i][m] && cards[j][m] != cards[l][m]) || (cards[j][m] == cards[l][m] && cards[j][m] != cards[i][m])||(cards[l][m] == cards[i][m] && cards[j][m] != cards[l][m])) break;
                    if (m == k-1) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}