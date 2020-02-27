#include <bits/stdc++.h>
using namespace std;

int n;
long long int max_;
vector< vector <int>> tri;
vector < vector <long long int>> dp;

int max_prize(int i, int j){
    if (dp[i][j] != -37579){
        max_ = max(max_, dp[i][j]);
        return dp[i][j];
    }
    long long int value;
    if (i == n-1){
        dp[i][j] = tri[i][j];
        max_ = max(max_, dp[i][j]);
        return tri[i][j];
    }
    else if (i == n-2){
        dp[i][j] = tri[i][j] + tri[i+1][j] + tri[i+1][j+1];
        max_ = max(max_, dp[i][j]);
        return tri[i][j] + tri[i+1][j] + tri[i+1][j+1];
    } else {
        dp[i][j] = tri[i][j] + max_prize(i+1, j) + max_prize(i+1, j+1) - max_prize(i+2, j+1);
        max_ = max(max_, dp[i][j]);
        return dp[i][j];
    }
}

int main(){
    int b;
    tri.assign(1001, vector<int>());
    dp.reserve(1001);
    while (1){
        max_ = 0;
        cin >> n;
        if (!n) return 0;
        for (int i = 0; i < n; i++) {
            tri[i].reserve(i+1);
            dp[i].assign(i+1, -37579);
            for (int j = 0; j <= i; j++) {
                 cin >> tri[i][j];
            }
        }
        max_prize(0, 0);
        cout << max_ << "\n";
        for (int k = 0; k < n; k++) {
            for (int i = 0; i <= k ; ++i) {
                cout << dp[k][i]<<" ";
            }
            cout << "\n";
        }
    }
}
