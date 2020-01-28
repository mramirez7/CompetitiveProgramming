//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    int r, numbers[1000], m, sup, inf;
    while (cin >> k >> n) {
        sup = 0; inf = 0;
        for (int i = 1; i <= k; i++) {
            numbers[i] = 0;
        }
        for (int j = 0; j < n ; j++) {
            cin >> m;
            numbers[m]++;
        }
        int flag = 0;
        r = n / k;
        if (n%k == k-1) r++;
        for (int i = 1; i <= k ; i++) {
            if (numbers[i] > r+1 || numbers[i] < r-1) {
                cout << "*\n";
                flag = 1;
                break;
            }
            else if ((numbers[i] > r && sup) || (numbers[i] < r && inf)){
                cout << "*\n";
                flag = 1;
                break;
            }
            else if (numbers[i] > r) sup = i;
            else if (numbers[i] < r) inf = i;
        }
        if (flag) {
            flag = 0;
            continue;
        }
        if (n % k == 0) {//swap
            cout << "-" << sup << " +" << inf << "\n";
        } else if (n % k == 1) {//remove
            cout << "-" << sup << "\n";
        } else if (n%k == k-1) { //add
            cout << "+" << inf << "\n";
        } else {
            cout << "*\n";
        }
    }
}
