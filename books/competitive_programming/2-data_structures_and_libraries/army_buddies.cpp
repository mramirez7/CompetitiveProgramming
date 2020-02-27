//"WA"
#include <bits/stdc++.h>
using namespace std;
int rn[100003], ln[100003];
int main(){
    int s,b, l, r;
    while (1){
        cin >> s >> b;
        if (!(s+b)) break;
        for (int j = 0; j <= s; j++) {
            ln[j] = j-1;
            rn[j] = j+1;
        }
        ln[1] = -1;
        rn[s] = -1;
        for (int i = 0; i < b; i++) {
            cin >> l >> r;
            rn[ln[l]] = rn[r];
            ln[rn[r]] = ln[l];
            l = ln[l];
            r = rn[r];
            if (l+1) cout << l << " ";
            else cout << "* ";
            if (r+1) cout << r << "\n";
            else cout << "*\n";
        }
        cout << "-\n";
    }
}
