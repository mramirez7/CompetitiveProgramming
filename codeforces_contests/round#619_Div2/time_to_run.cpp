#include <bits/stdc++.h>
using namespace std;

vector <pair <int, char>> ans;

int main(){
    int n, m, i=1, j=1, moves = 0;
    long long k, t = 0;
    cin >> n >> m >> k;
    if (k > 4*m*n-2*m-2*n){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if (m == 1){
        if (n-1 >= k){
            cout << 1 << "\n" << k << " D\n";
        }else{
            cout << 2 << "\n" << n-1 << " D\n";
            cout << k - n+1 << " U\n";
        }
        return 0;
    }
    while (1){
        moves++;
        if (k <= t + m - 1){
            ans.push_back({k-t,'R'});
            t = k;
            break;
        }else{
            ans.push_back({m-1, 'R'});
            t += m-1;
            j = m;
        }
        if (i == n && j == m && n != 1) break;
        moves++;
        if (k <= t + m - 1){
            ans.push_back({k-t,'L'});
            t = k;
            break;
        }else{
            ans.push_back({m-1, 'L'});
            t += m-1;
            j = 1;
        }
        moves++;
        ans.push_back({1, 'D'});
        i++; t++;
        if (k == t) break;
    }
    while (t != k){
        moves++;
        if (k <= t + n - 1){
            ans.push_back({k-t,'U'});
            t = k;
            break;
        }else{
            ans.push_back({n-1, 'U'});
            t += n-1;
        }
        moves++;
        if (k <= t + n - 1){
            ans.push_back({k-t,'D'});
            t = k;
            break;
        }else{
            ans.push_back({n-1, 'D'});
            t += n-1;
        }
        moves++;
        ans.push_back({1, 'L'});
        t++;
    }
    cout << moves << "\n";
    for (int l = 0; l < ans.size(); ++l) {
        cout << ans[l].first << " " << ans[l].second << "\n";
    }
}