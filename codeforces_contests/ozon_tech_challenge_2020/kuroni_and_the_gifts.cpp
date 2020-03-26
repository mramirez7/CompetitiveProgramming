#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];

int main(){
    int t, n;
    cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        sort(a, a+n);
        sort(b, b+n);
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; ++i) cout << b[i] << " ";
        cout << "\n";
    }
}