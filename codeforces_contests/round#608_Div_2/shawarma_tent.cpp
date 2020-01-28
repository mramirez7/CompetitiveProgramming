#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long sx, sy, x, y;
    int I=0, II=0, III=0, IV=0;
    int a = 0, b= 0 , c=0, d=0;
    cin >> n >> sx >> sy;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x-sx > 0 && y-sy > 0) I++;
        if (x-sx < 0 && y-sy > 0) II++;
        if (x-sx < 0 && y-sy < 0) III++;
        if (x-sx > 0 && y-sy < 0) IV++;
        if (x-sx == 0 && y - sy > 0) a++;
        if (x-sx == 0 && y - sy < 0) c++;
        if (x-sx > 0 && y - sy == 0) d++;
        if (x-sx < 0 && y - sy == 0) b++;
    }
    a = a + I + II;
    b = b + II + III;
    c = c + III + IV;
    d = d + IV + I;
    int max_ = max(max(a,b), max(c, d));
    cout << max_ << "\n";
    if (max_ == a){
        cout << sx << " " << sy+1;
    } else if (max_ == b){
        cout << sx-1 << " " << sy;
    } else if (max_ == c){
        cout << sx << " " << sy-1;
    } else if (max_ == d){
        cout << sx+1 << " " << sy;
    }
    cout << "\n";
}