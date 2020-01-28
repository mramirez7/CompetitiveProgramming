#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long colors[3];
    cin >> n;
    while (n--){
        cin >> colors[0] >> colors[1] >> colors[2];
        sort(colors, colors+3);
        if (colors[2] > colors[0]+colors[1]+1) cout << "NO\n";
        else cout << "YES\n";
    }
}