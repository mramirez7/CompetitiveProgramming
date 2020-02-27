#include <bits/stdc++.h>
using namespace std;

long double EPS = 1E-12;

int main() {
    cout.precision(3);
    cout << fixed;
    int n, c = 0;
    long double d, v, u, fast, slow;
    cin >> n;
    while (n!=c){
        c++;
        cin >> d >> v >> u;
        if (u < EPS || v - u > -EPS || v < EPS){
            cout << "Case " << c << ": "<< "can't determine\n";
            continue;
        }
        fast = d/u;
        slow = d/(u*cos(asin(v/u)));
        cout << "Case " << c << ": " << slow-fast << "\n";
    }
    return 0;
}