#include <bits/stdc++.h>
using namespace std;

vector <int> visited;
vector <int> gifts;
int main(){
    int n;
    cin >> n;
    visited.assign(n,0);
    gifts.assign(n, 0);
    queue <int> conflictivos;
    queue <int> no_conf;
    for (int i = 0; i < n; ++i) {
        cin >> gifts[i];
        gifts[i]--;
        if (gifts[i] != -1){
            visited[gifts[i]] = 1;
        }
    }
    for (int j = 0; j < n; ++j) {
        if (!visited[j] && gifts[j] == -1)
            conflictivos.push(j);
        else if (!visited[j] && gifts[j] != -1)
            no_conf.push(j);
    }
    for (int k = 0; k < n; ++k) {
        if (gifts[k]!=-1){
            cout << gifts[k]+1 << " ";
            continue;
        }
        if (conflictivos.size()){
            if (conflictivos.front() != k){
                cout << conflictivos.front()+1 << " ";
                conflictivos.pop();
            }else if (conflictivos.front() == k && conflictivos.size() > 1){
                conflictivos.push(conflictivos.front());
                conflictivos.pop();
                cout << conflictivos.front()+1 << " ";
                conflictivos.pop();
            } else{
                cout << no_conf.front()+1 << " ";
                no_conf.pop();
            }
        }else{
            cout << no_conf.front()+1 << " ";
            no_conf.pop();
        }
    }
    return 0;
}