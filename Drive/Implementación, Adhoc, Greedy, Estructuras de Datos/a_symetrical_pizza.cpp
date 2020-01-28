//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    string r;
    int pos, numb = 0;
    cin >> r;
    pos = r.find(".");
    r.erase(pos,1);
    for (int i = 0; i < r.size(); i++) {
        numb *= 10;
        numb += (r[i]-'0');
    }
    int g = __gcd(numb,36000);
    cout << 36000/g << "\n";
}


