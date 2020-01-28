#include <bits/stdc++.h>
using namespace std;

vector <int> numb;

int main() {
    int n, v;
    cin >> n;
    while (n){
        numb.clear();
        for (int i = 0; i < n; ++i) {
            cin >> v;
            numb.push_back(v);
        }
        sort(numb.begin(), numb.end());
        for (int j = 0; j < n; ++j) {
            for (int i = j+1; i < n; ++i) {
                for (int k = i+1; k < n; ++k) {
                    for (int l = k+1; l < n; ++l) {
                        for (int m = l+1; m < n; ++m) {
                            for (int i1 = m+1; i1 < n; ++i1) {
                                cout << numb[j] << " " << numb[i] << " " << numb[k] << " " << numb[l] << " " << numb[m] << " " << numb[i1] << "\n";
                            }
                        }
                    }
                }
            }
        }
        cin >> n;
        if (n) cout << "\n";
    }
}