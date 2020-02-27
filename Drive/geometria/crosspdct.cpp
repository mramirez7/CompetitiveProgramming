//ACCEPED

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int x1, y1, x2, y2;
    long long int q, x, y;
    long long int v;
    cin >> x1 >> y1 >> x2 >> y2 >> q;
    x2 -= x1;
    y2 -= y1;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        x -= x1;
        y -= y1;
        v = (long long int) y2 * x - (long long int) y * x2;
        if (!v) cout << "C\n";
        else if (v > 0) cout << "D\n";
        else cout << "I\n";
    }
}
