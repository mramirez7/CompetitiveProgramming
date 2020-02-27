#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a < b) cout << "<\n";
        else if (b < a) cout << ">\n";
        else cout << "=\n";
    }
    return 0;
}
