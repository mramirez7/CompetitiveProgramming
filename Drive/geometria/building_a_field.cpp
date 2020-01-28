//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

set <int> circ;
int main() {
    int n;
    int v, sum_ = 0, diam = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        circ.insert(sum_ += v);
    }
    auto it = circ.begin();
    for (int j = 0; j < n; j++, it++) {
        if (circ.count((*it)+sum_/2)) diam++;
    }
    if (diam <= 1 || sum_%2) cout << "N\n";
    else cout << "Y\n";
}