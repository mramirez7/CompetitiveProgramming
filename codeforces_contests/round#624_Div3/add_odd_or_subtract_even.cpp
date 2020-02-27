#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (a == b) cout << "0\n";
        else if (b > a){
            if ((a%2) != (b%2)) cout << "1\n";
            else cout << "2\n";
        }else{
            if ((a%2) == (b%2)) cout << "1\n";
            else cout << "2\n";
        }
    }
    return 0;
}