//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, c, s, pos = 1, ins, ans = 0;
    cin >> n >> c >> s;
    for (int i = 0; i < c; i++) {
        if (pos%n == s%n) ans++;
        cin >> ins;
        pos += ins;
        if (!pos) pos = n;
    }
    if (pos%n == s%n) ans++;
    cout <<ans << "\n";
}
