//ACCEPTED

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
int gen[50001];
int pos[50001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, cases = 1, r, q;
    int R, L, p;
    while (cin >> n) {
        if (!n) break;
        cout << "Genome " << cases << "\n";
        cases++;
        cin >> r;
        for (int i = 0; i < 50001; i++) {
            gen[i] = i;
        }
        for (int j = 0; j < r; j++) {
            cin >> L >> R;
            while (L < R){
                swap(gen[L], gen[R]);
                L++; R--;
            }
        }
        cin >> q;
        for (int l = 1; l <= n; l++) {
            pos[gen[l]] = l;
        }
        for (int k = 0; k < q; k++) {
            cin >> p;
            cout << pos[p] << "\n";
            }
    }
}