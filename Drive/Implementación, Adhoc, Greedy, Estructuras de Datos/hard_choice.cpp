//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
 int main(){
     int c, b, p;
     int p_1, p_2, p_3;
     while (cin >> c >> b >> p){
         cin >> p_1 >> p_2 >> p_3;
         cout << max(p_1-c, 0) + max(p_2-b, 0) + max(p_3-p,0) << "\n";
     }
 }