//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

int isValidHouse(int n){
    vector <bool> visited;
    visited.assign(10,0);
    while (n){
        if (visited[n%10]) return 0;
        visited[n%10] = 1;
        n /= 10;
    }
    return 1;
}

int main(){
    int a, b, ans;
    while (cin >> a >> b){
        ans = 0;
        for (int i = a; i <= b; ++i) {
            ans += isValidHouse(i);
        }
        cout << ans << "\n";
    }
}


