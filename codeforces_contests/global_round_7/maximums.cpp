#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector <long long> a;
vector <long long> x;
vector <long long> b;

int main(){
    int n;
    long long max_ = 0;
    cin >> n;
    a.reserve(n+1);
    x.reserve(n+1);
    b.reserve(n+1);
    for (int i = 1; i <= n ; ++i) {
        cin >> b[i];
    }
    x[1] = 0;
    a[0] = 0;
    for (int j = 1; j <= n; ++j) {
        max_ = max(max_, a[j-1]);
        a[j] = b[j] + max_;
    }
    for (int k = 1; k <= n; ++k) {
        cout << a[k] << " ";
    }
}