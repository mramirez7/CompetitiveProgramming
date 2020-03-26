#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
pair <int, int> dif[1001];
vector <vector <int>> removed;

int main() {
    int n, concavo = 0, convexo = 0, conc_sum, operaciones = 0;
    string s;
    cin >> s;
    n = s.size();
    removed.assign(n, vector <int> ());
    for (int i = 0; i < n; ++i){
        if (s[i] == '(')
            convexo++;
        visited[i] = false;
        dif[i].first = convexo;
    }
    concavo = n-convexo;
    conc_sum = 0;
    for (int j = 0; j < n; ++j) {
        if (s[j] == ')') conc_sum++;
        dif[j].second = concavo-conc_sum;
    }
    while (1){
        int ind;
        for (ind = 0; ind < n; ++ind) {
            if (s[ind] == '(' && !visited[ind]) {
                visited[ind] = true;
                removed[operaciones].push_back(ind+1);
            }
            if (dif[ind].first == dif[ind].second) break;
        }
        if (dif[ind].first == 0) break;
        int close = removed[operaciones].size();
        concavo -= close;
        convexo = 0;
        for (int i = n-1; i >= 0; i--) {
            if (!close) break;
            if (s[i] == ')'){
                removed[operaciones].push_back(i+1);
                visited[i] = true;
                close--;
            }
            if (!close) break;
        }
        sort(removed[operaciones].begin(), removed[operaciones].end());
        for (int j = 0; j < n; ++j) {
            if (visited[j]) {
                dif[j] = {-1,-2};
                continue;
            }
            if (s[j] == '(') convexo++;
            else concavo--;
            dif[j] = {convexo, concavo};
        }
        operaciones++;
    }
    cout << operaciones << "\n";
    for (int k = 0; k < operaciones; ++k) {
        cout << removed[k].size() << "\n";
        for (int i = 0; i < removed[k].size(); ++i) {
            cout << removed[k][i] << " ";
        }
    }
    cout << "\n";
}