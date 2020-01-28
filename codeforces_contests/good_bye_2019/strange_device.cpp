#include <bits/stdc++.h>
using namespace std;

vector <long long> numb;
int main(){
    int n, k, index, value, c;
    cin >> n >> k;
    numb.assign(n,-1);
    set <int> st;
    for (int i = 0; i < k; ++i) {
        st.insert(i);
    }
    c = k;
    while (n--){
        cout << "? ";
        auto it = st.begin();
        while (1) {
            cout << *it+1 << " ";
            it++;
            if (it == st.end())break;
        }
        cout << "\n";
        cout << flush;
        cin >> index >> value;
        numb[index-1] = value;
        st.erase(index-1);
        st.insert(c);
        c++;
    }
    for (int j = 0; j < n; ++j) {
        cout << numb[j] << " ";
    }
    return 0;
}