//ACCEPTED
//TAGS: FLOYD-WARSHALL

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int dist[26][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b, ans = "";
    int changes, cost;
    char char1, char2;
    cin >> a >> b >> changes;
    for (int j = 0; j < 26; ++j) {
        for (int i = j; i < 26; ++i) {
            dist[i][j] = INT_MAX/2;
            dist[j][i] = INT_MAX/2;
            if (i==j) dist[i][i] = 0;
        }
    }
    for (int i = 0; i < changes; ++i) {
        cin >> char1 >> char2 >> cost;
        dist[char1-'a'][char2-'a'] = min(dist[char1-'a'][char2-'a'], cost);
    }
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    if (a.size() != b.size()){
        cout << "-1\n";
        return 0;
    }
    cost = 0;
    int aux_cost;
    char letter;
    for (int l = 0; l < a.size(); ++l) {
        aux_cost = INT_MAX/2;
        letter = '$';
        for (int i = 0; i < 26; ++i) {
            if (aux_cost > dist[a[l]-'a'][i] + dist[b[l]-'a'][i]){
                aux_cost = dist[a[l]-'a'][i] + dist[b[l]-'a'][i];
                letter = i + 'a';
            }
        }
        if (letter == '$' || aux_cost == INT_MAX/2){
            cout << "-1\n";
            return 0;
        }
        cost += aux_cost;
        ans += letter;
    }
    cout << cost << "\n" << ans<<"\n";
}