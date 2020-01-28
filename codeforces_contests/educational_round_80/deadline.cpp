#include <bits/stdc++.h>
using namespace std;

long double EPS = 1E-10;

long long ceil(long double j){
    if (fabs(j-(long long)j) < EPS) return (long long)j;
    else return (long long)j + 1;
}

int main(){
    int t;
    long long n, d, inf, sup, bin;
    long double a;
    cin >> t;
    while (t--){
        cin >> n >> d;
        if (n >= d) cout << "YES\n";
        else{

        }
    }
    return 0;
}