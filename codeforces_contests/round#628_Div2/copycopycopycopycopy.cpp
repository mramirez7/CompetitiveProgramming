#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n, aux;
    cin >> t;
    while (t--){
        set <int> st;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> aux;
            if (st.find(aux) == st.end()) st.insert(aux);
        }
        cout << st.size() << "\n";
    }
}