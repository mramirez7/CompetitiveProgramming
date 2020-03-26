#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, a, b, c, A, B, C, ans, ans_;
    int AA, BB, CC;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        ans = INT_MAX;
        for (int A = 1; A < 2*a; ++A) {
            for (int B = A; B < 2*b; B += A) {
                if (B%A != 0) continue;
                ans_ = abs(a - A);
                ans_ += abs(B-b);
                ans_ += min(c%B, B - c%B);
                if (ans_ < ans){
                  AA = A;BB = B; CC = c%B < B - c%B ? c-c%B : c-c%B + B;
                  ans = ans_;
                }
            }
        }
        cout << ans << "\n" << AA << " " << BB << " " << CC << "\n";
     }
}