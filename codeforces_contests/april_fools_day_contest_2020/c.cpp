#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int main(){
    int t, ans = 0;
    cin >> t;
    vi b = {16, 2, 8, 4, 1, 32};
    for (int i = 0; i < 7; ++i) {
        if (t&(1<<i)) ans += b[i];
    }
    cout << ans << "\n";
}