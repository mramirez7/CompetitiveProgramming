#include <bits/stdc++.h>
using namespace std;

int dr[8] = {1,1,0,-1,-1,-1,0,1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};
vector <string> board;
int R, C;

int floodfill(int r, int c, char c1, char c2){
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (board[r][c] != c1)
        return 0;
    int ans = 1;
    board[r][c] = c2;
    for (int d = 0; d < 8; ++d) {
        ans += floodfill(r+dr[d], c+dc[d], c1, c2);
    }
    return ans;
}

int main(){
    int t, i, j;
    string aux;
    cin >> t;
    cin >> aux;
    board.push_back(aux);
    while (t--){
        while (1) {
            cin >> aux;
            if (aux[0] == 'L' || aux[0] == 'W') board.push_back(aux);
            else break;
        }
        R = board.size();
        C = board[0].size();
        i = 0;
        for (int k = 0; k < aux.size(); ++k) {
            i *= 10;
            i += (aux[k] - '0');
        }
        cin >> j;
        i--; j--;
        cout << floodfill(i,j,'W','.') << "\n";
        while (cin >> aux){
            if (aux[0] == 'L' || aux[0] == 'W') {
                board.clear();
                board.push_back(aux);
                if (t) cout << "\n";
                break;
            }
            i = 0;
            for (int k = 0; k < aux.size(); ++k) {
                i *= 10;
                i += (aux[k]-'0');
            }
            cin >> j;
            i--; j--;
            if (board[i][j] == 'W'){
                cout << floodfill(i,j,'W','.') << "\n";
            }
            else {
                cout << floodfill(i,j,'.','W') << "\n";
            }
        }

    }
}