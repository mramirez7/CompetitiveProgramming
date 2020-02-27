//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, p, ans, ans2;
    int first, second;
    deque <int> couples;
    deque <int> couples2;
    while (cin >> n){
        ans = 0;
        ans2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> p;
            couples.push_back(p);
            couples2.push_back(p);
        }
        sort (couples.begin(), couples.end());
        sort (couples2.begin(), couples2.end());

        while (couples.size()) {
            first = couples.front(); couples.pop_front();
            second = couples.front(); couples.pop_front();
            ans += min(24-(second-first), second-first);
        }
        first = couples2.front(); couples2.pop_front();
        second = couples2.back(); couples2.pop_back();
        ans2 += min(24-(second-first), second-first);
        while (couples2.size()) {
            first = couples2.front(); couples2.pop_front();
            second = couples2.front(); couples2.pop_front();
            ans2 += min(24-(second-first), second-first);
        }
        cout << min(ans, ans2) << "\n";
    }
}
