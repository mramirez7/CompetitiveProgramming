#include <bits/stdc++.h>
using namespace std;

vector <bool> visited;

int main() {
    int n, p, a, flag;
    while (cin >> n){
        flag = 0;
        visited.assign(n, false);
        cin >> p;
        for (int i = 0; i < n-1; ++i) {
            cin >> a;
            visited[abs(a-p)] = true;
            p = a;
        }
        for (int j = 1; j < n; ++j) {
            if (!visited[j]){
                flag = 1;
                break;
            }
        }
        if (flag) cout << "Not jolly\n";
        else cout << "Jolly\n";
    }
}