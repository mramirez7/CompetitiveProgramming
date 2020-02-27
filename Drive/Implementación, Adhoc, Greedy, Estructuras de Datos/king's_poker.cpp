//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
  int c_1, c_2, c_3;
  int pareja, sola;
  while (1){
   cin >> c_1 >> c_2 >> c_3;
   if(!(c_1+c_2+c_3)) break;
   if (c_1 == c_2 && c_1 == c_3){
       if (c_1 == 13) cout << "*\n";
       else cout << c_1+1 << " " << c_1+1 << " " << c_1+1 << "\n";
       continue;
   } else if (c_1 == c_2) pareja = c_1, sola = c_3;
   else if (c_1 == c_3) pareja = c_1, sola = c_2;
   else if (c_2 == c_3) pareja = c_2, sola = c_1;
   else{
       cout << "1 1 2\n";
       continue;
   }
   if (pareja == 13 && sola == 12) cout << "1 1 1\n";
   else if (sola == 13) cout << "1 " << pareja+1 << " " << pareja+1 << "\n";
   else if (pareja-sola == 1) cout << min(pareja, sola+2) << " " << pareja << " " << max(pareja, sola+2) << "\n";
   else  cout << min(pareja, sola+1) << " " << pareja << " " << max(pareja, sola+1) << "\n";
  }
}
