#include <bits/stdc++.h>
using namespace std;

vector<long long> trial_division(long long n) {
    vector<long long> factors;
    for (long long d = 2; d*d <= n; d++) {
        while (n % d == 0) {
            factors.push_back(d);
            if ((n /= d) == 1) return factors;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

long long ans[3];

int main() {
    long long t, n, flag, c;
    cin >> t;
    while (t--) {
        cin >> n;
        c = 0;
        flag = 1;
        ans[2] = -1;
        vector <long long> primes = trial_division(n);
        long long index = -1;
        long long last = 0, count = 0;
        for (long long i = 0; i < primes.size() + 1; ++i) {
            if (i < primes.size() && primes[i] == last) count++;
            else {
                if (count >= 1 && c < 3) ans[c++] = last;
                if (count >= 3 && c < 3) ans[c++] = last*last;
                if (count >= 6 && c < 3) c++;
                if (i < primes.size()) last = primes[i]; count = 1;

            }
        }
        if (c < 2) cout << "NO\n";
        else {
            if (n/(ans[0]*ans[1]) == ans[0] || n/(ans[0]*ans[1]) == ans[1] || n/(ans[0]*ans[1]) == 1) cout << "NO\n";
            else cout << "YES\n" << ans[0] << " " << ans[1] << " " << n/(ans[0]*ans[1]) << "\n";
        }
    }
}