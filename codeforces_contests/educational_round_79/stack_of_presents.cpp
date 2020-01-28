#include <bits/stdc++.h>
using namespace std;

vector <int> stack_presents;

int main(){
    int t, n, m, p;
    long long ans;
    cin >> t;
    while (t--){
        ans=0;
        set <int> st;
        queue <int> santa_presents;
        cin >> n >> m;
        stack_presents.clear();
        stack_presents.reserve(n);
        for (int i = 0; i < n; ++i) {
            cin >> stack_presents[i];
        }
        for (int j = 0; j < m; ++j) {
            cin >> p;
            santa_presents.push(p);
        }
        for (int k = 0; k < n; ++k) {
            if (!santa_presents.size()) break;
            else if (st.find(santa_presents.front()) != st.end()) {
                ans+=1;
                st.erase(santa_presents.front());
                santa_presents.pop();
                k--;
                continue;
            }
            else if (stack_presents[k] != santa_presents.front()){
                st.insert(stack_presents[k]);
            } else {
                ans += st.size()*2+1;
                santa_presents.pop();
            }
        }
        ans += santa_presents.size();
        cout << ans << "\n";
    }
}