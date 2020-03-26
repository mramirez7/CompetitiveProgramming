#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        if (n == 1) cout << "-1\n";
        else{
            cout << 2;
            for (int i = 0; i < n-1; ++i) {
                cout << 9;
            }
            cout << "\n";
        }
    }
}