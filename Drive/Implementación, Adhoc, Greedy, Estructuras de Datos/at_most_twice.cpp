//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int apariciones[10], indice, change_index, flag, n_change;
    while (cin >> s){
        flag = 0;
        indice = -1;
        for (int j = 0; j < 10; j++) {
            apariciones[j] = 0;
        }
        for (int k = 0; k < s.size(); k++) {
            if (apariciones[s[k]-'0'] < 2) apariciones[s[k]-'0']++;
            else{
                apariciones[s[k]-'0']++;
                indice = k;
                break;
            }
        }
        if (indice == -1){
            cout << s << "\n";
            continue;
        }
        for (int i = indice; i >= 0; i--) {
            for (int j = s[i]-'0'-1; j >= 0 ; j--) {
                if (apariciones[j] < 2) {
                    apariciones[s[i]-'0']--;
                    s[i] = j+'0';
                    apariciones[j]++;
                    change_index = i;
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
            apariciones[s[i]-'0']--;
        }
        int puntero = 9;
        for (int l = change_index+1; l < s.size(); l++) {
            while (apariciones[puntero] >= 2) puntero--;
            s[l] = puntero+'0';
            apariciones[puntero]++;
        }
        if (s[0]-'0') cout << s[0];
        for (int m = 1; m < s.size(); m++) {
            cout << s[m];
        }
        cout << "\n";
    }
}
