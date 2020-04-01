#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

vvi g;
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x); }

int main(){
    int t, n;
    cin >> t;
    cout << "3 4\n";
    if (t%2 == 1) n = t+2;
    else n = t+1;
    int a = log2(n);
    int b = (1<<a);
    n = b-1;
    cout << b+n << " " << n << " " << n << " " << b << "\n";
    cout << b << " " << b << " " << n << " ";
    cout << n-t << "\n";
    cout << b << " " << b << " " << b+n << " " << n << "\n";
}