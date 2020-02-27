#include <bits/stdc++.h>
using namespace std;

vector <int> moves;

int main(){
    int n, ans = 0, flag = 0, W=0, B=0;
    string s, p = "";
    char a, c2;
    cin >> n >> s;
    for (int j = 0; j < s.size(); ++j) {
        if (s[j] == 'B') B++;
        else W++;
    }
    if (W % 2 && B % 2){
        cout << "-1\n";
        return 0;
    }
    c2 = 'B';
    if (W%2) c2 = 'W';
    for (int i = 0; i < n-1; ++i) {
        a = s[i];
        if ((a == c2 && !flag)|| (a != c2 && flag)) {
            moves.push_back(i+1);
            ans++;
            flag = 1;
            continue;
        }
        flag = 0;
    }
    if ((s[s.size()-1] != c2 && !flag) || s[s.size()-1] == c2 && flag){
        cout << ans << "\n";
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves[i] << " ";
        }
        cout << "\n";
        return 0;
    }else{
        for (int i = s.size() -3; i >= 0 ; i = i-2) {
            ans++;
            moves.push_back(i+1);
        }
        cout << ans << "\n";
        for (int l = 0; l < moves.size(); ++l) {
            cout << moves[l] << " ";
        }
        cout << "\n";
    }

}