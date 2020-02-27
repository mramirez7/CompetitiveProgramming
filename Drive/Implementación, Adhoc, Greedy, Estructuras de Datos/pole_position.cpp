#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

int main(){
    int n, delta_pos, car_id, flag;
    while (cin >> n){
        if (!n)return 0;
        flag = 0;
        ans.assign(n,-1);
        for (int i = 0; i < n; ++i) {
            cin >> car_id >> delta_pos;
            if (i + delta_pos < n && i + delta_pos >= 0 && ans[i+delta_pos] == -1) ans[i+delta_pos] = car_id;
            else flag = 1;
        }
        if (flag) cout << "-1\n";
        else{
            for (int i = 0; i < n; ++i) {
                cout << ans[i];
                if (i != n-1) cout << " ";
                else cout << "\n";
            }
        }
    }
}
