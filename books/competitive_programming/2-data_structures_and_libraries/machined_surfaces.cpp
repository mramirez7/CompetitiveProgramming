#include <bits/stdc++.h>
using namespace std;

vector <int> Bs;
int main() {
    int n, b, min_b, ans;
    string s;
    while (cin >> n){
        if (!n) return 0;
        Bs.clear();
        min_b = INT_MAX;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            b = 25;
            cin >> s;
            if (s.size() == 25) b = 0;
            else{
                b -= s.size();
                cin >> s;
                b -= s.size();
            }
            min_b = min(min_b, b);
            Bs.push_back(b);
        }
        for (int k = 0; k < n; ++k) {
            ans += Bs[k] - min_b;
        }
        cout << ans << "\n";
    }
}