#include <bits/stdc++.h>
using namespace std;

int s, route[20000];
int memo[20002][20002];

int main() {
    int b, r = 0, flag, L, R, L_ans;
    long long sum, ans;
    cin >> b;
    while (b!=r){
        r++;
        sum = 0;
        ans = 0;
        flag = 0;
        cin >> s;
        L = 0;
        L_ans = 0;
        for (int i = 0; i < s-1; ++i) {
            cin>>route[i];
            if (route[i] > 0) flag = 1;
            sum += route[i];
            if ((sum > ans) || (sum == ans && i - L > R - L_ans)){
                ans = sum;
                R = i;
                L_ans = L;
            }if (sum < 0){
                L = i+1;
                sum = 0;
            }
        }
        if (!flag){
            cout << "Route " << r << " has no nice parts\n";
        }else cout << "The nicest part of route " << r << " is between stops " << L_ans+1 << " and " << R+2 << "\n";
    }
}