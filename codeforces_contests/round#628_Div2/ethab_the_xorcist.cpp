#include <bits/stdc++.h>
using namespace std;

int main(){
    long long u, v, a;
    cin >> u >> v;
    a = (v - u)/2;
    if (u > v || (u % 2 != v % 2))
        cout << "-1\n";
    else if (u == v && !u)
        cout << u << "\n";
    else if (u == v)
        cout << "1\n" << u << "\n";
    else if (((u + a) ^ a) == u)
        cout << "2\n" <<u + a << " " << a;
    else
        cout << "3\n" <<u << " " << a << " " << a << "\n";
}