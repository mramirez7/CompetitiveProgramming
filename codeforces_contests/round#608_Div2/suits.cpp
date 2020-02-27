#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    if (e > f){
        cout << e*min(a,d) + f*min(d-min(a,d), min(b,c)) << "\n";
    } else{
        cout << f*min(b,min(c,d)) + e*min(a, d-min(b,min(c,d))) << "\n";
    }
}