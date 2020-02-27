#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, target, ciclos;
    long long n, g, b, ans;
    cin >> t;
    while (t--){
        ans = 0;
        cin >> n >> g >> b;
        if (g >= b) cout << n << "\n";
        else{
            target = (n+1)/2;//3
            ciclos = target/g;//1
            if (target%g == 0) ciclos--;
            ans = ciclos*(g+b);// ans = 10
            ans += target - (ciclos*g);
            cout << max(ans, n) << "\n";
        }
    }
    return 0;
}