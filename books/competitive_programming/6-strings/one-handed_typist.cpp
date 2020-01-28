//WA
#include <bits/stdc++.h>
using namespace std;

string QWERTY = "4567890-=qwertyuiop[]asdfgjkl;'zxcvbm,./$%^&*()_+QWERTYUIOP{}ASDFGJKL:\"ZXCVBM<>?1";
string DVOARK = "qjlmfp/[]456.orsuyb;=789aetdck-0zx,iwvg'QJLMFP?{}$%^>ORSUYB:+&*(AETDCK_)ZX<IWVG\"1";
map <char, char> translator;

int main(){
    char a, b;
    string line;
    for (int i = 0; i < 100; ++i) {
        a = QWERTY[i]; b = DVOARK[i];
        if (a == '1') break;
        translator.insert({a, b});
    }
    while (getline(cin, line)){
        for (int i = 0; i < line.size(); ++i) {
            if (translator.find(line[i]) != translator.end()) cout << translator.find(line[i])->second;
            else cout << line[i];
        }
    }
}