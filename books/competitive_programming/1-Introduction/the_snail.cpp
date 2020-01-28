//WA por no usar float creo
#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, u, d, f, c;
    int p, delta_pos, u_;
    while (cin >> h >> u >> d >> f){
        if (!h) break;
        delta_pos = u*f;
        h *= 100;
        u *= 100;
        d *= 100;
        p = 0;
        c = 0;
        while (1){
            c++;
            if (c >= 2){
                u -= delta_pos;
                if (u < 0) u = 0;
            }
            p += u;
            if (p > h){
                cout << "success on day " << c << "\n";
                break;
            }
            p -= d;
            if (p <= 0){
                cout << "failure on day " << c << "\n";
                break;
            }
        }
    }
}
