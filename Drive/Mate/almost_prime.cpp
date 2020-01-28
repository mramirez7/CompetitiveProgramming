#include <bits/stdc++.h>
using namespace std;

set <int> st;
vector <int> primes;
vector <int> amount_prime_div;

int main(){
    int n, ans = 0;
    cin >> n;
    amount_prime_div.assign(n, 0);
    for (int i = 2; i < n/2+1; ++i) {
        st.insert(i);
    }
    while (st.size()){
        auto it = st.begin();
        primes.push_back(*it);
        int a = *it;
        st.erase(it);
        int p = a*a;
        while  (p <= n/2+1){
            if (st.find(p) != st.end()) st.erase(p);
            p += a;
        }
    }
    for (int j = 0; j < primes.size(); ++j) {
        for (int i = 1; i <= n; ++i) {
            if (!(i%primes[j])) amount_prime_div[i-1]++;
        }
    }
    for (int k = 0; k < n; ++k) {
        if (amount_prime_div[k] == 2) ans++;
    }
    cout << ans << "\n";
}


