#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> adj;
vector <int> fire;
vector <char> ans;
int main(){
    int k, v, u, flag;
    string s;
    char a, b;
    while (cin >> s){
        if (s[0] == '#') break;
        cin >> a >> b >> k;
        ans.clear();
        adj.clear();
        adj.assign(26, vector <int>());
        flag = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == ';'){
                flag = 0;
                continue;
            }
            if (flag == 0) {
                v = (int) (s[i] - 'A');
                flag = 1;
            }else if (flag == 1){
                flag = 2;
            } else if (flag == 2){
                if (s[i] == ';' || s[i] == '.'){
                    flag = 0;
                    continue;
                }
                adj[v].push_back((int)(s[i]-'A'));
            }
        }
        fire.assign(26, 0);
        //for (int j = 0; j < 26; ++j) sort(adj[j].begin(), adj[j].end());
        u = (int)(b-'A');
        v = (int)(a-'A');
        int cuevas = 0;
        while (1){
            flag = 0;
            for (auto i: adj[v]) {
                if (i != u && !fire[i]){
                    //cout << (char)(i+'A') << "\n";
                    cuevas++;
                    u = v;
                    v = i;
                    flag = 1;
                    if (cuevas%k == 0){
                        ans.push_back((char)(u+'A'));
                        fire[u] = 1;
                    }
                    break;
                }
            }
            if (!flag) break;
        }
        for (int l = 0; l < ans.size(); ++l) {
            cout << ans[l] << " ";
        }
        cout << "/" << (char)(v+'A') << "\n";
    }
}