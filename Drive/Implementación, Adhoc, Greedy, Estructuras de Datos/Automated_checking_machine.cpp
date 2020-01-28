//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d, e;
    int a_,b_,c_,d_, e_;
    while (cin >> a >> b >> c >> d >> e) {
        cin >> a_ >> b_ >> c_ >> d_ >> e_;
        if (a ^ a_ && b ^ b_ && c ^ c_ && d ^ d_ && e ^ e_) cout << "Y\n";
        else cout << "N\n";
    }
}
