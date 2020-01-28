#include <bits/stdc++.h>
using namespace std;

vector <long long> trees;
vector <long long> res;

int main(){
    int n,m;
    long long y, ans = 0, d, x;
    cin >>n>>m;
    set <long long> st;
    priority_queue <pair<long long, long long>> min_heap;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        st.insert(y);
        trees.push_back(y);
    }
    for (int j = 0; j < trees.size() ; ++j) {
        if (st.find(trees[j]-1) == st.end()){
            min_heap.push({-1, trees[j]-1});
            st.insert(trees[j]-1);
        }
        if (st.find(trees[j]+1) == st.end()){
            min_heap.push({-1, trees[j]+1});
            st.insert(trees[j]+1);
        }
    }
    for (int k = 0; k < m; ++k) {
        d = min_heap.top().first; x = min_heap.top().second;
        min_heap.pop();
        ans -= d;
        res.push_back(x);
        st.insert(x);
        if (st.find(x-1) == st.end()){
            min_heap.push({d-1, x-1});
            st.insert(x-1);
        }
        if (st.find(x+1) == st.end()){
            min_heap.push({d-1, x+1});
            st.insert(x+1);
        }
    }
    cout << ans << "\n";
    for (int l = 0; l < m; ++l) {
        cout << res[l] << " ";
    }
    cout << "\n";

    return 0;
}