#include <bits/stdc++.h>
using namespace std;

int numb[100000];

int main(){
    int t, n;
    long long sum_, xor_;
    cin >> t;
    while (t--){
        cin >> n;
        sum_ = 0;
        xor_ = 0;
        for (int i = 0; i < n; ++i) {
            cin >> numb[i];
            sum_ += numb[i];
            xor_ ^= numb[i];
        }
        if (sum_ == 2*xor_) cout << "0\n\n";
        else{
            cout << 2 << "\n";
                cout << xor_ << " ";
                cout << sum_+xor_ << "\n";
        }
    }
    return 0;
}