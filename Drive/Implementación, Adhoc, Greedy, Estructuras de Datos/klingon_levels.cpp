//ACCEPTED

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int matrix[10000][1001];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, s, cont, value;
    int ans, sum_;
    priority_queue <int> students;
    while (cin >> n){
        ans = 999999;
        sum_ = 0;
        if (!n) break;
        cont = 0;
        for (int i = 0; i < n; i++) {
            cin >> m;
            for (int j = 0; j < m; j++) {
                cin >> s; students.push(-s);
            }
            value = 0;
            for (int k = 0; k <= 1000; k++) {
                if (k == -students.top() && students.size()){
                    value++;
                    students.pop();
                    k--;
                }
                matrix[cont][k] = (abs(m-value-value));
            }
            cont++;
        }

        for (int l = 0; l < 1001; l++) {
            for (int i = 0; i < n; i++) {
                sum_ += matrix[i][l];
            }
            ans = min(ans, sum_);
            sum_ = 0;
        }
        cout << ans << "\n";
    }
}