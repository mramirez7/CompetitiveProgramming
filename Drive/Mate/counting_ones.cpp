//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

long long freqA[2];
long long freqB[2];

void solve (long long n, long long *freq) {
    if (!n) return;
    long long m = 1;
    for (int j = 0; j < 55; ++j) {
        for (int i = 0; i < 2; ++i) {
            freq[i] += m*(n/(2*m));
        }
        if (n>m-1) {
            freq[(n/m)%2] += n%m+1;
        }
        m *= 2;
    }
}

int main(){
    long long a, b;
    while (cin >> a >> b){
        if (!(a|b)) return 0;
        freqA[1] = (freqB[1] = 0);
        solve(a-1, freqA);
        solve(b, freqB);
        cout << freqB[1]-freqA[1] << "\n";
    }
}


