#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, mOdd, mEven, jOdd, jEven, aux;
    while (cin >> n){
        if (!n) return 0;
        mEven = 0;
        mOdd = 0;
        jEven = 0;
        jOdd = 0;
        for (int i = 0; i < n; ++i) {
            cin >> aux;
            if (aux%2) mOdd++;
            else mEven++;
        }
        for (int i = 0; i < n; ++i) {
            cin >> aux;
            if (aux%2) jOdd++;
            else jEven++;
        }
        cout << n - min(mEven,jOdd) - min(mOdd, jEven) << "\n";
    }
}
