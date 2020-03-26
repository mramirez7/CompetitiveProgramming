#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> t;
priority_queue <int> q;
vector <pair<int, int>> vec;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, aux;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        a.push_back(aux);
    }
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        t.push_back(aux);
    }
    for (int j = 0; j < n; ++j) {
        vec.push_back({a[j], -t[j]});
    }
    sort(vec.begin(), vec.end());
    int pointer = 0;
    int last  = vec[0].first;
    long long sum_ = 0, ans = 0;
    while (pointer != n){
        if (vec[pointer].first == last){
            q.push(-vec[pointer].second);
            sum_ += -vec[pointer++].second;
            continue;
        }
        sum_ -= q.top(); q.pop();
        ans += sum_;
        if (q.size()) last++;
        else last = vec[pointer].first;
    }
    while (q.size()){
        sum_ -= q.top(); q.pop();
        ans += sum_;
    }
    cout << ans << "\n";
}