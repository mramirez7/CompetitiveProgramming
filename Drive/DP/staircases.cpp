//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

long long memo[505][505];

long long solve(int blocks, int last_h){
    if (blocks <= last_h){
        memo[blocks][last_h] = 0;
        return 0;
    }else if (memo[blocks][last_h] != -1){
        return memo[blocks][last_h];
    }
    long long ans = 1;
    for (int i = last_h+1; i < blocks; ++i) {
        ans += solve(blocks-i, i);
    }
    memo[blocks][last_h] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            memo[i][j] = -1;
        }
    }
    cout << solve(n, 0)-1<<"\n";
}
