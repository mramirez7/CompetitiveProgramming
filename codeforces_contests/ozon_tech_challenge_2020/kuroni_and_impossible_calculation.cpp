#include <bits/stdc++.h>
using namespace std;

vector <long long> abs_;
vector <long long> numb;
vector <long long> numb_mod;
int n, mod;

int main() {
    int aux;
    cin >> n >> mod;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        numb.push_back(aux);
        numb_mod.push_back(aux);
        numb_mod[i] %= mod;
    }
    sort(numb_mod.begin(), numb_mod.end());
    for (int l = 1; l < numb.size(); ++l) {
        if (numb_mod[l] == numb_mod[l-1]) {
            cout << "0\n";
            return 0;
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = j+1; i < n; ++i) {
            abs_.push_back(abs(numb[j]-numb[i]));
        }
    }
    long long ans = 1;
    for (int k = 0; k < abs_.size(); ++k) {
        ans *= abs_[k];
        ans %= mod;
    }
    cout << ans << "\n";
}