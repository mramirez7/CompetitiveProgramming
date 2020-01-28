#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, s[3], c = 0;
    cin >> t;
    while (t--){
        c++;
        for (int i = 0; i < 3; ++i) {
            cin >> s[i];
        }
        sort(s, s+3);
        cout << "Case " << c << ": " <<s[1] << "\n";
    }
}
