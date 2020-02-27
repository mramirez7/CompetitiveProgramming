#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector <string> matrix;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    char ans[81];
    cin >> n;
    while (n--){
        matrix.assign(10, "");
        for (int k = 0; k < 81; ++k) ans[k] = 0;
        for (int i = 0; i < 10; ++i) {
            cin >> matrix[i];
        }
        m = matrix[0].size();
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= 8; ++i) {
                if (matrix[i][j] != '/') {
                    ans[j-1] += (1 << (i-1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}