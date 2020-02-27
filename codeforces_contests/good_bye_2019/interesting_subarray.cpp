#include <bits/stdc++.h>
using namespace std;

long long numb[200000];

int main(){
    int t, n, p1, p2, flag;
    cin >> t;
    while (t--){
        flag = 0;
        cin >> n;
        p1 = 0;
        p2 = 1;
        for (int i = 0; i < n; ++i) {
            cin >> numb[i];
        }
        for (int j = 0; j < n-1; ++j) {
            if (abs(numb[j]-numb[j+1])>= 2){
                cout << "YES\n" << j+1 << " " << j+2 << "\n";
                flag = 1;
                break;
            }
        }
        if (!flag) cout << "NO\n";
    }
    return 0;
}