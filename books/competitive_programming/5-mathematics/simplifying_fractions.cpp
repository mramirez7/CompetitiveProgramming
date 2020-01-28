#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long num, den, g;
    char s;
    cin >> n;
    while (n--){
        cin >> num >> s >> den;
        g = __gcd(num, den);
        num /= g;
        den /= g;
        cout << num << " / " << den << "\n";
    }
}