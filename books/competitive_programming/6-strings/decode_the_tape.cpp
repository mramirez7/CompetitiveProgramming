#include <bits/stdc++.h>
using namespace std;

vector <string> tape;

int main(){
    string line;
    getline(cin,line);
    int point;
    line[2] = 'a';
    while (1){
        getline(cin,line);
        if (line[2] == '_') break;
        tape.push_back(line);
    }
    char ans[tape.size()];
    for (int k = 0; k < tape.size(); ++k) ans[k] = 0;
    for (int i = 0; i < tape.size(); ++i) {
        point = 0;
        for (int j = 1; j < 10; ++j) {
            if (tape[i][j] == '.') continue;
            ans[i] *= 2;
            if (tape[i][j] == 'o') ans[i] += 1;
        }
    }
    cout << ans;
}