#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main(){
    int t, n, k;
    cin >> t;
    while (t--){
        cin >> n >> k;
        if (n%2 != k%2){
            cout << "NO\n";
            continue;
        }
        else{
            if (n >= (long long)k*k)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}