//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string numbers_1[10] =  {".*", "*.",  "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
    string numbers_2[10] =  {"**", "..",  "*.", "..", ".*", ".*", "*.", "**", "**", "*."};
    string digits, mode, pair_, brai;
    vector <string> braille;
    while (1){
        cin >> n;
        if (!n) break;
        cin >> mode;
        if (mode == "S"){
            cin >> digits;
            for (int i = 0; i < digits.size(); i++) {
                cout << numbers_1[digits[i]-'0'];
                if (i+1 < digits.size()) cout << " ";
            }
            cout << "\n";
            for (int i = 0; i < digits.size(); i++) {
                cout << numbers_2[digits[i]-'0'];
                if (i+1 < digits.size()) cout << " ";
            }
            cout << "\n";
            for (int i = 0; i < digits.size(); i++) {
                cout << "..";
                if (i+1 < digits.size()) cout << " ";
            }
            cout << "\n";
        }else{
            braille.assign(n, "");
            for (int i = 0; i < n*3; i++) {
                cin >> pair_;
                if (i<2*n) braille[i%n] += pair_;
            }
            for (int j = 0; j < n; j++) {
                brai = braille[j];
                if (!brai.compare(".***")) cout << 0;
                else if (!brai.compare("*...")) cout << 1;
                else if (!brai.compare("*.*.")) cout << 2;
                else if (!brai.compare("**..")) cout << 3;
                else if (!brai.compare("**.*")) cout << 4;
                else if (!brai.compare("*..*")) cout << 5;
                else if (!brai.compare("***.")) cout << 6;
                else if (!brai.compare("****")) cout << 7;
                else if (!brai.compare("*.**")) cout << 8;
                else cout << 9;
            }
            cout << "\n";
        }
    }
}
