#include <bits/stdc++.h>
using namespace std;

vector <long long> numbers;

int main(){
    int t, n;
    long long a, max_limit, min_limit, max_abs;
    cin >> t;
    while (t--){
        cin >> n;
        numbers.clear();
        max_abs = 0;
        max_limit = 0;
        min_limit = 100000000000;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            if (!i) {
                numbers.push_back(a);
                continue;
            }
            if (a == -1 && numbers[numbers.size()-1] == a) continue;
            numbers.push_back(a);
            if (a != -1 && numbers[numbers.size()-2] != -1) max_abs = max(max_abs, abs(a-numbers[numbers.size()-2]));
            else if (a == -1){
                max_limit = max(max_limit, numbers[numbers.size()-2]);
                min_limit = min(min_limit, numbers[numbers.size()-2]);
            }else{
                max_limit = max(max_limit, a);
                min_limit = min(min_limit, a);
            }
        }
        if ((max_limit+min_limit)/2 == 50000000000) min_limit = 0;
        cout << max(max_abs, max(max_limit-(max_limit+min_limit)/2, (max_limit+min_limit)/2-min_limit)) << " " << (max_limit+min_limit)/2 << "\n";
    }
    return 0;
}