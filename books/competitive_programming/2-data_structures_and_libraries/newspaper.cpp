#include <bits/stdc++.h>
using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
    int n, k, value, lines;
    unsigned long long ans;
    string text;
    unsigned char caracter;
    cin >> n;
    while (n--){
        ans = 0;
        map <unsigned char, int> mapeo;
        mapeo.clear();

        cin >> k;
        for (int i = 0; i < k; ++i) {
             cin >> caracter >> value;
             mapeo.insert({caracter, value});
        }

        cin >> lines;
        cin.ignore();

        for (int l = 0; l < lines; ++l) {
            while ((caracter = cin.get()) != '\n'){
                if (mapeo.find(caracter) != mapeo.end()) ans += mapeo.find(caracter)->second;
            }
        }
        printf("%.2lf$\n", ans / 100.0);
    }
}