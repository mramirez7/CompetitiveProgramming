//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int b, d, p;
    int sum_, best_d, current_d;
    while (cin >> n >> m){
        current_d = 0;
        best_d = 0;
        for (int j = 0; j < m; j++) {
            cin >> b >> d;
            sum_ = 0;
            sum_ = d;
            for (int i = 0; i < n - 1; i++) {
                cin >> p;
                sum_ += p;
            }
            if (sum_ <= b) current_d += d;
            sum_ -= d;
            if (sum_ >= b) continue;
            int card = 10000;
            while (sum_ + card > b){
                card /= 10;
            }
            best_d += card;
        }
        cout << best_d - current_d << "\n";
    }
}
