#include <bits/stdc++.h>
using namespace std;

struct triple{
    int a, b, c;
};
set < triple> st;

int main(){
    int t, a, b, c, A, B, C, ans;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> a >> b >> c;
        queue <triple> q;
        q.push({a,b,c});
        while (q.size()){
            A = q.front().a;
            B = q.front().b;
            C = q.front().c;
            if (st.find(q.front()) != st.end()){
                q.pop();
                continue;
            }else{
                st.insert(q.front());
                q.pop();
                if (C%B == 0 && B%A == 0){
                    break;
                }
                q.push({A,B,C+1});
                if (C!=B) q.push({A,B,C-1});
                if (B != C) q.push({A,B+1,C});
                if (B != A) q.push({A,B-1,C});
                if (A != B) q.push({A+1,B,C});
                if (A != 1) q.push({A-1,B,C});
            }
        }
        ans += abs(c-C);
        ans += abs(a-A);
        ans += abs(b-B);
        cout << ans << "\n";
        cout << A << " " << B << " " << C << "\n";
    }
}