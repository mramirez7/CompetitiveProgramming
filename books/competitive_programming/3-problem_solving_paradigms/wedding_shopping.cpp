#include <bits/stdc++.h>
using namespace std;

int garments[20][22];
int m, c;
int memo[202][22];

int shop(int money, int g){
    if (c == g) return m - money;
    if (memo[money][g] != -1) return memo[money][g];
    int ans = -INT_MAX;
    for (int i = 1; i <= garments[g][0]; ++i) {
        if (money - garments[g][i] >= 0) ans = max(ans, shop(money-garments[g][i], g+1));
    }
    memo[money][g] = ans;
    return ans;
}

int main() {
    int n, v, no_solution_sum;
    cin >> n;
    while (n--){
        cin >> m >> c;
        no_solution_sum = 0;
        for (int l = 0; l <= m; ++l) {
            for (int i = 0; i <= c; ++i) {
                memo[l][i] = -1;
            }
        }
        for (int i = 0; i < c; ++i) {
            cin >> garments[i][0];
            for (int j = 1; j <= garments[i][0]; ++j) {
                cin >> garments[i][j];
            }
            sort(garments[i]+1, garments[i] + garments[i][0]+1);
        }
        for (int k = 0; k < c; ++k) {
            no_solution_sum += garments[k][1];
        }
        if (no_solution_sum > m) {
            cout << "no solution\n";
        }else cout << shop(m,0) << "\n";
    }
}