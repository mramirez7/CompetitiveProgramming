//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long g, b;
    vector <long long> bandas;
    priority_queue <long long> cola;
    cin >> n;
    cin >> g;
    for (int i = 1; i < n; i++) {
        cin >> b;
        cola.push(-1*b);
    }
    while (cola.size()){
        b = cola.top();
        g += b*cola.size() +1;
        cola.pop();
    }
    if (g <= 0) cout << "NO\n";
    else cout << "SI\n";
}
