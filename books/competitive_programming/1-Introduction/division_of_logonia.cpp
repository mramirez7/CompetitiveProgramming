#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, x,y, a, b;
    while (cin >> q){
        cin >> x >> y;
        for (int i = 0; i < q; ++i) {
            cin >> a >> b;
            if (a > x && b > y) cout << "NE\n";
            else if (a > x && b < y) cout << "SE\n";
            else if (a < x && b > y) cout << "NO\n";
            else if (a < x && b < y) cout << "SO\n";
            else cout << "divisa\n";
        }
    }
}
