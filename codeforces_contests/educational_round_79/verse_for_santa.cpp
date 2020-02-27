#include <bits/stdc++.h>
using namespace std;

vector <long long> song;

int main(){
    int t, n, max_index, sum_, flag;
    long long s, max_value;
    cin >> t;
    while (t--){
        flag = 0;
        max_index = 0;
        max_value = 0;
        sum_ = 0;
        cin >> n >> s;
        song.clear();
        song.reserve(n);
        for (int i = 0; i < n; ++i) {
            cin >> song[i];
        }
        for (int i = 0; i < n; ++i) {
            if (sum_ + song[i] > s && flag){
                break;
            }
            if (sum_ + song[i] > s && !flag){
                sum_ -= max(song[i], max_value);
                flag = 1;
            }
            if (max_value < song[i]){
                max_value = song[i];
                max_index = i+1;
            }
            sum_ += song[i];
        }
        if (flag) cout << max_index << "\n";
        else cout << "0\n";
    }
}