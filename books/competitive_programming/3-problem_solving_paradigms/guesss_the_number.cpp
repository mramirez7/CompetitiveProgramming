#include <bits/stdc++.h>
using namespace std;

int main() {
    int inf = 1, sup = 1000000, bin;
    string judge;
    for (int i = 0; i < 25; ++i) {
        bin = (sup+inf)/2;
        cout << bin << "\n";
        cout << flush;
        cin >> judge;
        if (judge[0] == '<'){
            sup = bin-1;
        }else inf = bin;
        if (sup-inf <= 1) break;
    }
    if (!(sup-inf)){
        cout << "! " << sup << "\n";
        return 0;
    } else{
        cout << sup << "\n";
        cout << flush;
        cin >> judge;
        if (judge[0] == '<') {
            cout << "! " << inf << "\n";
        } else cout << "! " << sup << "\n";
    }
}