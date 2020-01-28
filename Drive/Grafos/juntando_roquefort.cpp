//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

vector<int> parents;
vector <int> roq;
vector<int> ans;
vector<int> ans_cmp;

int main(){
    int n, d;
    int ans_node, v, flag;
    cin >> n >> d;
    parents.reserve(n);
    roq.reserve(n);
    ans.assign(d, 0);
    ans_cmp.reserve(d);
    for (int i = 0; i < n; ++i) {
        cin >> roq[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> parents[j];
        parents[j]--;
    }
    for (int k = 0; k < n; ++k) {
        flag = 1;
        v = k;
        ans_cmp[0] = roq[k];
        for (int i = 1; i < d; ++i) {
            if (parents[v] == -2){
                flag = 0;
                break;
            }
            v = parents[v];
            ans_cmp[i] = roq[v];
        }
        if (!flag) continue;
        flag = 0;
        for (int j = d-1; j >= 0; j--) {
            if (ans[j] > ans_cmp[j] && !flag) break;
            else if (ans[j] < ans_cmp[j] || flag){
                flag = 1;
                ans[j] = ans_cmp[j];
            }
        }
    }
    for (int l = d-1; l >= 0 ; --l) {
        cout << ans[l] << " ";
    }
    cout << "\n";
    return 0;
}

