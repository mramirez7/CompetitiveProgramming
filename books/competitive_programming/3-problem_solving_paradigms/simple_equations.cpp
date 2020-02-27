#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, flag;
    cin >> n;
    while (n--){
        flag = 0;
        cin >> a >> b >> c;
        for (int i = -100; i < 100; ++i) {
            for (int j = i+1; j < 100; ++j) {
                for (int k = j+1; k < 100; ++k) {
                    if (i+j+k == a && i*j*k == b && i*i+j*j+k*k == c){
                        flag = 1;
                        cout << i << " " << j << " " << k << "\n";
                        break;
                    }
                }
            }
        }
        if (!flag)cout << "No solution.\n";
    }
}