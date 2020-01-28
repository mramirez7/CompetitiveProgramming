//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x, a,max_local = 1, max_global = 1, pos;
    cin >> n >>x;
    cin >> pos;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a-pos <= x) max_local++;
        else {
            max_global = max(max_global,max_local);
            max_local = 1;
        }
        pos = a;
    }
    max_global = max(max_global,max_local);
    cout << max_global << "\n";
}
