//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

string board[100];
bool visited[100][100];
int r, c;


bool isValid(int i, int j){
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main(){
    while (cin >> r >> c){
        if(!(r|c)) break;
        for (int k = 0; k < r; ++k) {
            for (int i = 0; i < c; ++i) {
                visited[k][i] = false;
            }
        }
        queue <pair<int, int>> q;
        queue <pair<int, int>> q2;
        for (int i = 0; i < r; ++i) {
            cin >> board[i];
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == 'I') {
                    q.push({i, j});
                    board[i][j] = '(';
                    visited[i][j] = true;
                }
            }
        }
        int cw, i_, j_;
        while (q.size()){
          i_ = q.front().first; j_ = q.front().second; q.pop();
            visited[i_][j_] = true;
          cw = (board[i_][j_] == '(' ? 1: 0);
          if (isValid(i_- 1, j_) && board[i_-1][j_] != '.'){
              if (!visited[i_ - 1][j_]){
                  board[i_ - 1][j_] = (cw ? ')': '(');
                  q.push({i_-1, j_});
              }else{
                  if (board[i_][j_] == board[i_-1][j_]){
                      board[i_-1][j_] = 'B';
                      q2.push({i_, j_});
                  }
              }
          }
          //
            if (isValid(i_- 1, j_+1) && board[i_-1][j_+1] != '.'){
                if (!visited[i_ - 1][j_+1]){
                    board[i_ - 1][j_+1] = (cw ? ')': '(');
                    q.push({i_-1, j_+1});
                }else{
                    if (board[i_][j_] == board[i_-1][j_+1]){
                        board[i_-1][j_+1] = 'B';
                        q2.push({i_, j_});
                    }
                }
            }
            //
            if (isValid(i_, j_+1) && board[i_][j_+1] != '.'){
                if (!visited[i_ ][j_+1]){
                    board[i_][j_+1] = (cw ? ')': '(');
                    q.push({i_, j_+1});
                }else{
                    if (board[i_][j_] == board[i_][j_+1]){
                        board[i_][j_+1] = 'B';
                        q2.push({i_, j_+1});
                    }
                }
            }
            //
            if (isValid(i_+ 1, j_) && board[i_+1][j_] != '.'){
                if (!visited[i_ + 1][j_]){
                    board[i_ + 1][j_] = (cw ? ')': '(');
                    q.push({i_+1, j_});
                }else{
                    if (board[i_][j_] == board[i_+1][j_]){
                        board[i_+1][j_] = 'B';
                        q2.push({i_, j_});
                    }
                }
            }
            //
            if (isValid(i_+ 1, j_-1) && board[i_+1][j_-1] != '.'){
                if (!visited[i_ +1][j_-1]){
                    board[i_ + 1][j_-1] = (cw ? ')': '(');
                    q.push({i_+1, j_-1});
                }else{
                    if (board[i_][j_] == board[i_+1][j_-1]){
                        board[i_+1][j_-1] = 'B';
                        q2.push({i_, j_});
                    }
                }
            }
            //
            if (isValid(i_, j_-1) && board[i_][j_-1] != '.'){
                if (!visited[i_][j_-1]){
                    board[i_][j_-1] = (cw ? ')': '(');
                    q.push({i_, j_-1});
                }else{
                    if (board[i_][j_] == board[i_][j_-1]){
                        board[i_][j_-1] = 'B';
                        q2.push({i_, j_});
                    }
                }
            }
            //
        }
        for (int k = 0; k < r; ++k) {
            for (int i = 0; i < c; ++i) {
                visited[k][i] = false;
            }
        }
        while (q2.size()){
            i_ = q2.front().first; j_ = q2.front().second; q2.pop();
            if (visited[i_][j_]) continue;
            visited[i_][j_] = true;
            board[i_][j_] = 'B';
            if (isValid(i_- 1, j_) && board[i_-1][j_] != '.') q2.push({i_-1, j_});
            if (isValid(i_- 1, j_+1) && board[i_-1][j_+1] != '.') q2.push({i_-1, j_+1});
            if (isValid(i_, j_+1) && board[i_][j_+1] != '.') q2.push({i_, j_+1});
            if (isValid(i_+ 1, j_) && board[i_+1][j_] != '.') q2.push({i_+1, j_});
            if (isValid(i_+ 1, j_-1) && board[i_+ 1][j_- 1] != '.') q2.push({i_+1, j_-1});
            if (isValid(i_, j_-1) && board[i_][j_-1] != '.') q2.push({i_, j_-1});
        }
        cout << "\n";
        for (int l = 0; l < r; ++l) {
            for (int i = 0; i < c; ++i) {
                if (board[l][i] != '*') cout << board[l][i];
                else cout << 'F';
            }
            cout << "\n";
        }
    }
    return 0;
}
