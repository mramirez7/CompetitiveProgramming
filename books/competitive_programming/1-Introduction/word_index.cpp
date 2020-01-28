#include <bits/stdc++.h>
using namespace std;

string words[300000];

int main() {
    int c = 0;
    for (int n = 0; n < 26; ++n) {
        words[c] = n + 'a';
        c++;
    }
    for (int i1 = 0; i1 < 26; ++i1) {
        for (int i = i1+1; i < 26; ++i) {
            words[c] = (i1 + 'a');
            words[c] += (i + 'a');
            c++;
        }
    }
    for (int j1 = 0; j1 < 26; ++j1) {
        for (int i = j1+1; i < 26; ++i) {
            for (int j = i+1; j < 26; ++j) {
                words[c] = j1 + 'a';
                words[c] += i + 'a';
                words[c] += j + 'a';
                c++;
            }
        }
    }
    for (int k1 = 0; k1 < 26; ++k1) {
        for (int i = k1+1; i < 26; ++i) {
            for (int j = i+1; j < 26; ++j) {
                for (int k = j+1; k < 26; ++k) {
                    words[c] = k1 + 'a';
                    words[c] += i + 'a';
                    words[c] += j + 'a';
                    words[c] += k + 'a';
                    c++;
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = i+1; j < 26; ++j) {
            for (int k = j+1; k < 26; ++k) {
                for (int l = k+1; l < 26; ++l) {
                    for (int m = l+1; m < 26; ++m) {
                        words[c] = i + 'a';
                        words[c] += j + 'a';
                        words[c] += k + 'a';
                        words[c] += l + 'a';
                        words[c] += m + 'a';
                        c++;
                    }
                }
            }
        }
    }
    map <string, int> mapeo;
    for (int l1 = 0; l1 < 83681; ++l1) {
        mapeo.insert({words[l1], l1+1});
    }
    string s;
    while (cin >> s){
        if (mapeo.find(s) == mapeo.end()) cout << "0\n";
        else cout << mapeo.find(s)->second << "\n";
    }
    return 0;
}