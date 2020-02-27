//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

long long freqA[10];
long long freqB[10];

void solve (int n, long long *freq) {
    if (!n) return;
    int m = 1;
    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 10; ++i) {
            freq[i] += m*(n/(10*m));
            if ((n/m)%10 > i) freq[i] += m;
        }
        if (n>m-1) {
            freq[(n/m)%10] += n%m+1;
            freq[0] -= m;
        }
        m *= 10;
    }
}

int main(){
    int a, b;
    while (cin >> a >> b){
        if (!(a|b)) return 0;
        for (int i = 0; i < 10; ++i) freqA[i] = (freqB[i] = 0);
        solve(a-1, freqA);
        solve(b, freqB);
        for (int j = 0; j < 10; ++j) {
            cout << freqB[j]-freqA[j];
            if (j!=9)cout<< " ";
        }
        cout << "\n";
    }
}


