#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c;
    c = -c;
    d = gcd(a, b);
    if (c % d) cout << "-1\n";
    else

}


