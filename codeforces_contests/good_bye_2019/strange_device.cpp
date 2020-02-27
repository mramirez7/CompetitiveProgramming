#include <bits/stdc++.h>
using namespace std;

int a[505];

int main(){
    int n, k, pos, a_pos;
    pair <int, int> ans1 = {-1, 0}, ans2 = {-1, 0};
    cin >> n >> k;
    for (int j = 1; j <= k+1; ++j) {
        cout << "?";
        for (int i = 1; i <= k+1; ++i) {
            if (i != j) cout << " " << i;
        }
        cout << "\n";
        cout << flush;
        cin >> pos >> a_pos;
        if (ans1.first == -1 || ans1.first == a_pos) {
            ans1.first = a_pos;
            ans1.second++;
        }else{
            ans2.first = a_pos;
            ans2.second++;
        }
    }
    if (ans1.first < ans2.first) cout << "! " << ans2.second << "\n";
    else cout << "! " << ans1.second << "\n";
}