//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c, x, y, z, cards[53], pos_x, pos_y, min_;
    while (1){
        for (int i = 0; i < 54; i++) {
            cards[i] = 0;
        }
        cin >> a >> b >> c >> x >> y;
        if (!(a+b+c+x+y)) break;
        cards[a] = 1;
        cards[b] = 1;
        cards[c] = 1;
        cards[x] = 1;
        cards[y] = 1;
        if (a > b) swap(a,b);
        if (a > c) swap(a,c);
        if (b > c) swap(b,c);
        if (x > y) swap(x,y);
        if (x > c){
            min_ = 1;
            while (cards[min_]) min_++;
        }else if(y > c && x < b){
            min_ = c;
            while (cards[min_]) min_++;
        }else if(x>b){
            min_ = b;
            while (cards[min_]) min_++;
        }else min_ = 53;
        if (min_ == 53) cout << "-1\n";
        else cout << min_ << "\n";
    }
}
