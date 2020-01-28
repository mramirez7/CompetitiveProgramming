//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

vector <queue <pair<int, int>>> qs;
vector <string> board;
long long speed[10];
int n,m,p;

void bfs(int a) {
    int siz = qs[a].size();
    int i,j;
    for (int k = 0; k < siz; ++k) {
        i = qs[a].front().first, j = qs[a].front().second;
        qs[a].pop();
        if (i>0 && board[i-1][j] == '.'){
            board[i-1][j] = a+'0';
            qs[a].push({i-1,j});
        }
        if (i+1<n && board[i+1][j] == '.'){
            board[i+1][j] = a+'0';
            qs[a].push({i+1,j});
        }
        if (j>0 && board[i][j-1] == '.'){
            board[i][j-1] = a+'0';
            qs[a].push({i,j-1});
        }
        if (j+1<m && board[i][j+1] == '.'){
            board[i][j+1] = a+'0';
            qs[a].push({i,j+1});
        }
    }
}

bool is_game_finished(){
    for (int i = 0; i < qs.size(); ++i) {
        if (qs[i].size()) return false;
    }
    return true;
}

int main() {
    string line;
    cin >> n >> m >> p;
    board.assign(n, "");
    qs.assign(p+1, queue< pair<int, int>>());
    for (int i = 1; i <= p; ++i) {
        cin >> speed[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> line;
        board[j] += line;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < m; ++i) {
            if (board[k][i]-'0' >= 1 && board[k][i]-'0'< 10){
                qs[board[k][i]-'0'].push({k,i});
            }
        }
    }
    while (!is_game_finished()){
        for (int i = 1; i <= p; ++i) {
            for (int j = 1; j <= speed[i]; ++j) {
                if (qs[i].size()) bfs(i);
                else break;
            }
        }
    }
    vector <int> ans;
    ans.assign(p+1,0);
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < m; ++i) {
            if (board[l][i]-'0' >= 1 && board[l][i]-'0'< 10) {
                ans[board[l][i]-'0']++;
            }
        }
    }
    for (int i1 = 1; i1 <= p ; ++i1) {
        cout << ans[i1] << " ";
    }
    cout << "\n";
}