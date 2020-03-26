#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int n, m, k;
    string ans = "";
    cin >> n >> m;
    for (int i = 0; i < m-1; ++i) {
        ans += "L";
    }
    for (int i = 0; i < n-1; ++i) {
        ans += "U";
    }
    for (int j = 0; j < n; ++j) {
        if (j%2==0){
            for (int i = 0; i < m-1; ++i) {
                ans += "R";
            }
        }
        if (j%2==1){
            for (int i = 0; i < m-1; ++i) {
                ans += "L";
            }
        }
        if (j != n-1) ans += "D";
    }
    cout << ans.size() << "\n";
    cout << ans << "\n";
}