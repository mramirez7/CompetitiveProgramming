#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;
    cin >> t;
    while (t--){
        cin >> n;
        s = "";
        if (n%2){
            s += "7";
            n -= 3;
        }
        for (int i = 0; i < n/2; ++i) {
            s += "1";
        }
        cout << s <<"\n";
    }
    return 0;
}