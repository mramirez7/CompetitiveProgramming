#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vi primes = {2,3,5,7,11,13,17,19,23,29,31};

int main(){
    int t, f1 = 0, f2 = 0;
    cin >> t;
    for (int i = 2; i < t; ++i) {
        if (t%i == 0) {
            cout << i << t/i << "\n";
            return 0;
        }
    }
}