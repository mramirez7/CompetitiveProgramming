#include <bits/stdc++.h>
using namespace std;

vector <int> freq;

int main(){
    int n, c, k, v, min_;
    while (cin >> n >> c >> k){
        if (!(n|c|k)) return 0;
        freq.assign(k, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> v;
                freq[--v]++;
            }
        }
        min_ = INT_MAX;
        for (int l = 0; l < k; ++l) {
            min_ = min(freq[l], min_);
        }
        int flag = 0;
        for (int m = 0; m < k; ++m) {
            if (flag && freq[m] == min_) cout << " ";
            else if (!flag && freq[m] == min_) flag = 1;
            if (freq[m] == min_) cout << m+1;
        }
        cout << "\n";
    }
}

