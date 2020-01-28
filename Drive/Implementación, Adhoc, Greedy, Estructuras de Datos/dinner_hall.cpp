#include <bits/stdc++.h>
using namespace std;

vector<pair<string, string>> events;
int main(){
    int n, ans, qm, es, xs, h, q_acum;
    string hour, action;
    while (cin >> n){
        if (!n) return 0;
        events.clear();
        qm = 0;
        es = 0;
        xs = 0;
        q_acum = 0;
        ans = 0;
        h = 0;
        for (int i = 0; i < n; ++i) {
            cin >> hour >> action;
            events.push_back({hour, action});
            if (action[0] == '?') qm++;
            if (action[0] == 'E') es++;
            if (action[0] == 'X') xs++;
        }
        if (es > xs) qm -= (es - xs);
        else if (es < xs) qm += (xs - es);
        qm /= 2;
        sort(events.begin(), events.end());
        for (int j = 0; j < n; ++j) {
            if (events[j].second[0] == 'E') h++;
            else if (events[j].second[0] == '?' && qm) {
                h++;
                qm--;
            }else{
                ans = max(ans, h + q_acum - max(0, q_acum - qm/2));
                h--;
            }
        }
        cout << ans << "\n";
    }
}
