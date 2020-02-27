#include <bits/stdc++.h>
using namespace std;

int n, r, c, k;
int table[100][100];
int table1[100][100];

bool isValid(int i, int j){
    if (i>=0 && i<r && j>=0 && j < c) return true;
    return false;
}

int main(){
    while (cin >> n >> r >> c >> k){
        if (!(n+r+c+k)) return 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> table[i][j];
                table1[i][j] = table[i][j];
            }
        }
        for (int l = 0; l < k; ++l) {
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (isValid(i+1,j) && table[i+1][j] == (table[i][j]+1)%n)
                        table1[i+1][j] = table[i][j];
                    if (isValid(i-1,j) && table[i-1][j] == (table[i][j]+1)%n)
                        table1[i-1][j] = table[i][j];
                    if (isValid(i,j+1) && table[i][j+1] == (table[i][j]+1)%n)
                        table1[i][j+1] = table[i][j];
                    if (isValid(i,j-1) && table[i][j-1] == (table[i][j]+1)%n)
                        table1[i][j-1] = table[i][j];
                }
            }
            for (int m = 0; m < r; ++m) {
                for (int i = 0; i < c; ++i) {
                    table[m][i] = table1[m][i];
                }
            }
        }
        for (int i1 = 0; i1 < r; ++i1) {
            for (int i = 0; i < c; ++i) {
                cout << table[i1][i];
                if (i != c-1) cout << " ";
                else cout << "\n";
            }
        }
    }
}