//ACCEPTED
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector <int> back;
vector <string> words;
vector <pair<string, int>> ans;

bool ans_cmp(pair<string, int> p1, pair<string, int> p2){
    string s1 = p1.first, s2 = p2.first;
    if (s1.size() != s2.size()) return s1.size() < s2.size();
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) return s1[i] < s2[i];
    }
    return p1.second < p2.second;
}

void kmp_preprocess(string s){
    int i = 0, j = -1;
    back.reserve(s.size()+1); back[0] = -1;
    while (i < s.size()){
        while (j >= 0 && s[i] != s[j]) j = back[j];
        i++; j++; back[i] = j;
    }
}

int kmp_search(string t, string p){
    int i = 0, j = 0;
    while (i < t.size()){
        while (j >= 0 && t[i] != p[j]) j = back[j];
        i++; j++;
        if (j == p.size()) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    string qq;
    cin >> n;
    words.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> qq;
        words[i] = qq;
    }
    cin >> q;
    for (int j = 0; j < q; ++j) {
        ans.clear();
        cin >> qq;
        kmp_preprocess(qq);
        for (int i = 0; i < n; ++i) {
            if (kmp_search(words[i], qq)) ans.push_back({words[i], i+1});
        }
        int flag = 0;
        sort(ans.begin(), ans.end(), ans_cmp);
        for (int k = 0; k < min(10,(int)ans.size()); ++k) {
            if (flag) cout << " ";
            else flag = 1;
            cout << ans[k].second;
        }
        if (!ans.size()) cout << "-1";
        cout << "\n";
    }
}