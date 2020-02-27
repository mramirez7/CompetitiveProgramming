#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> t;
priority_queue <pair<int, int>> q;

int main(){
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
        q.push({-a[j], t[j]});
    }
    long long ans = 0;
    int a_, a_last = -1, t_;
    vector <int> vec;
    while (q.size()){
        a_ = -q.top().first; t_ = q.top().second; q.pop();
        if (a_ == a_last){
            vec.push_back(-t_);
        }if (a_ != a_last || (vec.size() && !q.size())){
            sort(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); ++i) {
                ans -= vec[i]*(i+1);
                q.push({-a_last-i-1, -vec[i]});
            }
            if (vec.size()) q.push({-a_, t_});
            if (a_last == -1 || !vec.size()) a_last = a_;
            else a_last = -1;
            vec.clear();
        }
    }
    cout << ans << "\n";
}