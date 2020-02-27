//ACCEPTED

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
multiset <int> slimes;
vector <long long int> repro;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n;
    for (long long int i = 0; i < (long long int)1<<n; i++) {
        cin >> s;
        slimes.insert(s);
    }
    slimes.insert(0);
    auto it = --slimes.end();
    repro.push_back(*it);
    slimes.erase(it);
    while (slimes.size() > 1){
        int size_ = repro.size();
        for (int i = 0; i < size_; i++) {
            auto it2 = slimes.lower_bound(repro[i]);
            it2--;
            if (!(*it2)){
                cout << "No\n";
                return 0;
            }
            slimes.erase(it2);
            repro.push_back(*it2);
        }
    }
    cout << "Yes\n";
}