//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, dif, W, B;
    long long ans;
    deque <int> right;
    deque <int> left;
    string stones;
    long long costo_adyacente;
    while (cin >> a >> b){
        ans = 0, W = 0, B = 0;
        dif = a-b;
        cin >> stones;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] == 66) B++;
            else W++;
        }
        for (int j = 0; j < stones.size(); j++) {
            if (stones[j] == 87 && j < B) left.push_back(j);
            else if (stones[j] == 66 && j >= B) right.push_back(j);
        }
        while (left.size()){
            costo_adyacente = (long long)dif*(B - left.back()) + (long long)dif*(right.front()-B);
            if (costo_adyacente < a){
                ans += costo_adyacente;
                right.pop_front();
            }else{
                ans += a;
                right.pop_back();
            }
            left.pop_back();
        }
        cout << ans<<"\n";
    }
}
