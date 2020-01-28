#include <bits/stdc++.h>
using namespace std;

int main(){
    long double h, l, ans;
    cout.precision(10);
    cout << fixed;
    cin >> h >> l;
    ans = (h*h-l*l)/(2*h);
    cout << -ans << "\n";
    return 0;
}