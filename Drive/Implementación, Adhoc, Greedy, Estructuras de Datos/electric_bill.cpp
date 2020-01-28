//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

int price(int cwh){
    int ans = 0;
    ans += min(cwh, 100)*2;
    cwh -= 100;
    if (cwh > 0) ans += min(cwh, 9900)*3;
    cwh -= 9900;
    if (cwh > 0) ans += min(cwh, 990000)*5;
    cwh -= 990000;
    if (cwh>0) ans += cwh*7;
    return ans;
}

int cwh(int price){
    int ans;
    ans += min(price, 200)/2;
    price -= 200;
    if (price > 0) ans += min(price,9900*3)/3;
    price -= 3*9900;
    if (price>0) ans += min(price, 990000*5)/5;
    price -= 5*990000;
    if (price>0) ans += price/7;
    return ans;
}

int main(){
    int A, B;
    int total_price, total_cwh;
    while (cin >> A >> B){
        if (!(A|B)) return 0;
        total_cwh = cwh(A);

        int inf, sup, bin_vec;
        inf = total_cwh/2;
        sup = total_cwh;
        while (1){
            bin_vec = (sup+inf)/2;
            if (price(bin_vec) - price(total_cwh-bin_vec) == B) break;
            else if (price(bin_vec) - price(total_cwh-bin_vec) > B) sup = bin_vec;
            else if (price(bin_vec) - price(total_cwh-bin_vec) < B) inf = bin_vec;
        }
        cout << price(total_cwh-bin_vec) << "\n";
    }
}
