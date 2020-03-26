#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int main(){
    int t, a, b;
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (a%b == 0) cout << "0\n" ;
        else cout << a/b*b + b - a << "\n";
    }
}