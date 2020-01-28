//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

map <string, int> mapeo;
map <int, string> mapeo2;
vector<vector<int>> graph;
vector<int> topsorted;
vector<int> visited;

void topsort(int v){
    visited[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        if (!visited[graph[v][i]]) topsort(graph[v][i]);
    }
    topsorted.push_back(v);
}

int main(){
    int n, c = 0;
    cin >> n;
    graph.assign(n, vector<int>());
    visited.assign(n, 0);
    string word, word2, word3, target;
    while (n){
        cin >> word2;
        if (word2[word2.size()-1] == ':') {
            n--;
            word = word2.substr(0,word2.size()-1);
            if (mapeo.find(word) == mapeo.end()){
                mapeo2[c] = word;
                mapeo[word] = c++;
            }
            continue;
        }
        if (mapeo.find(word2) == mapeo.end()){
            mapeo2[c] = word2;
            mapeo[word2] = c++;
        }
        graph[mapeo.find(word2)->second].push_back(mapeo.find(word)->second);
    }
    cin >> word2;
    while (1){
        if (cin >> word3){
            graph[mapeo.find(word2)->second].push_back(mapeo.find(word)->second);
        }else{
            target = word2;
            break;
        }
        word2 = word3;
    }
    topsort(mapeo.find(target)->second);
    for (int i = topsorted.size()-1; i >= 0; i--) {
        cout << mapeo2.find(topsorted[i])->second << " ";
    }
    cout << "\n";
    return 0;
}

