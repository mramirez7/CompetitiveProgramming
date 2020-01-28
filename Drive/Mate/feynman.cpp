#include <bits/stdc++.h>
using namespace std;

long long memo[101];

int main(){
    int n;
    long long sum = 0;
    for (int i = 1; i < 101; ++i) {
        sum += i*i;
        memo[i] = sum;
    }
    while (cin >> n) {
        if (!n) return 0;
        cout << memo[n] << "\n";
    }
}
