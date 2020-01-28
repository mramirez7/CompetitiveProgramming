#include <bits/stdc++.h>
using namespace std;

string words[300000];

int main() {
 int n;
 cin >> n;
 while (n--){
     priority_queue <int> green;
     priority_queue <int> blue;
     vector <int> battle_green;
     vector <int> battle_blue;
     int battles, sg, sb, a;
     cin >> battles >> sg >> sb;
     battle_blue.reserve(sb);
     battle_green.reserve(sg);
     for (int i = 0; i < sg; ++i) {
         cin >> a;
         green.push(a);
     }
     for (int j = 0; j < sb; ++j) {
         cin >> a;
         blue.push(a);
     }
     while (1){
         int g_size = green.size();
         int b_size = blue.size();
         int min_aux = min(min(g_size, b_size), battles);
         if (!min_aux) break;
         for (int i = 0; i < min_aux; ++i) {
             battle_blue[i] = blue.top();
             battle_green[i] = green.top();
             blue.pop(); green.pop();
         }
         for (int j = 0; j < min_aux; ++j) {
             if (battle_blue[j] > battle_green[j]) blue.push(battle_blue[j] - battle_green[j]);
             if (battle_blue[j] < battle_green[j]) green.push(-1*battle_blue[j] + battle_green[j]);
         }
     }
     if (green.size()){
         cout << "green wins\n";
         while (green.size()){
             cout << green.top() << "\n";
             green.pop();
         }
     }
     else if (blue.size()){
         cout << "blue wins\n";
         while (blue.size()){
             cout << blue.top() << "\n";
             blue.pop();
         }
     }else{
         cout << "green and blue died\n";
     }
     if (n) cout << "\n";
 }
}