#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector<vector<int>> g;
set <int> st;
set <string> ans;

void dfs (string s, set <int> vis, set <int> notvis){
    notvis.erase(s[s.size() - 1] - 'a');
    vis.insert(s[s.size() - 1] - 'a');
    if (s.size() == st.size()){
        ans.insert(s);
        return;
    }
    for (auto a: notvis) {
        int flag = 1;
        for (int i = 0; i < g[a].size(); ++i) {
            if (vis.find(g[a][i]) == vis.end()){
                flag = 0;
                break;
            }
        }
        if (flag) dfs(s+(char)(a+'a'), vis, notvis);
    }
}

int main(){
    string in;
    bool flag = false;
    while (getline(cin,in)){
        if (flag) cout << "\n";
        else flag = true;
        ans.clear();
        st.clear();
        g.clear();
        g.assign(26,  vector<int>());
        for (int i = 0; i < in.size(); i+=2) {
            st.insert((int)(in[i]-'a'));
        }
        getline(cin,in);
        for (int i = 0; i < in.size(); i+=4) {
            //g[in[i]-'a'].push_back(in[i+2]-'a');
            g[in[i+2]-'a'].push_back(in[i]-'a');
        }
        for (auto b: st) {
            if (g[b].size()) continue;
            string p = "";
            p += (char)(b+'a');
            dfs(p, set <int>(), st);
        }
        for (auto c: ans) {
            cout << c << "\n";
        }
    }
}