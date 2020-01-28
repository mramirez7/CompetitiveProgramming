//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
int hotels[100000];

int main(){
    int n, k, v;
    long long int total_sum = 0;
    priority_queue <int> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v;
        total_sum += v;
        hotels[i] = v;
        if (i == k) q.push(-1*v), total_sum -= v;
    }
    if (k >= n){
        cout << total_sum <<"\n";
        return 0;
    }
    for (int j = k+1; j < n; j++) {
        if (j-(q.size()*(k+1)) >= k) total_sum -= hotels[j], q.push(-1*hotels[j]);
        else if (q.top() > hotels[j]*-1 && j-(q.size()-1)*(k+1) >= k){
            total_sum -= (q.top()+hotels[j]);
            q.pop(), q.push(-1*hotels[j]);
        }
    }
    cout << total_sum << "\n";
}
