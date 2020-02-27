//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d, r;
    cin >> a >> b >> c >> d;
    r =  max(a-b-c+d,  -1*(a-b-c+d));
    cout << r << "\n";
}