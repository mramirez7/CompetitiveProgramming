//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, c, ans;
    vector <int> cards;
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cards.push_back(c);
    }
    c = cards[n-1];
    for (int j = n-2; j >= 0; j--) {
        if (cards[j] >= c) ans--;
        c = cards[j];
    }
    cout << ans << "\n";
}
