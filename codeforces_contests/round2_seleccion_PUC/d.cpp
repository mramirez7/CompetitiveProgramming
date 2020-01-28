#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> a;
vector <int> b;

struct job{
    int pay, days;
};

vector <pair<int,int>> jobs;

int main(){
    cin >> n >> m;
    a.assign(n, -1);
    b.assign(n, -1);
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        jobs.push_back({a[i], b[i]});
        //q.push({b[i], a[i]});
    }
    sort(jobs.begin(), jobs.end());
    queue <pair<int, int>> cola;
    for (int k = 0; k < jobs.size(); ++k) {
        cola.push(jobs[k]);
    }
    long long ans = 0;
    for (int j = 0; j < m; ++j) {
        while (cola.size()){
            if (cola.front().first <= j+1){
                q.push(cola.front().second);
                cola.pop();
            }else break;
        }
        if (q.size()){
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << "\n";
}