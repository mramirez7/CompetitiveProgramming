#include <bits/stdc++.h>
using namespace std;

vector <int> back;
vector<string> names;
vector<string> codes;
map <char, char> mapeo;
map <string, string> mapeo_code_inv;

int main() {
    int j = 2, n = 0, flag;
    string in, b;
    for (int i = 'a'; i <= 'z'; ++i) {
        mapeo.insert({i,j+'0'});
        mapeo.insert({i+'A'-'a',j+'0'});
        if (i == 'c' || i == 'f' || i == 'i' || i == 'l' || i == 'o' || i == 's'||i == 'v') j++;
    }
    while (cin >> in){
        if ((in[0] >= 'A' && in[0] <= 'Z')||(in[0] >= 'a' && in[0] <= 'z')){
            n++;
            char a = mapeo.find(in[0])->second;
            b = "";
            b += a;
            names.push_back(b);
            cin >> in;
            for (int i = 0; i < in.size(); ++i) {
                a = in[i];
                names[n-1] += mapeo.find(a)->second;
            }
            cin >> in;
            codes.push_back(in);
            mapeo_code_inv.insert({in, names[n-1]});
        }else{
            if (mapeo_code_inv.find(in) != mapeo_code_inv.end()) {
                cout << in << "\n";
            }
            else{
                flag = 0;
                for (int i = 0; i < n; ++i) {
                    if (in.size() > names[i].size()) continue;
                    for (int k = 0; k < in.size(); ++k) {
                        if (in[k] != names[i][k]) break;
                        else if (in[k] == names[i][k] && k == in.size()-1){
                            if (flag) cout << " " << codes[i];
                            else{
                                flag = 1;
                                cout << codes[i];
                            }
                        }
                    }
                }
                if (!flag) cout << "0";
                cout << "\n";
            }
        }
    }
}