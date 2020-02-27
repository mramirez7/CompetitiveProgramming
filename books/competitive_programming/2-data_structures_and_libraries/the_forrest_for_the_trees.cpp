#include <bits/stdc++.h>
using namespace std;

vector <int> letters;
int main() {
    int n, trees, acorn, nodos, cantidad_edges, forrest;
    string edge;
    cin >> n;
    while (n--){
        trees = 0; acorn = 0; nodos = 0; cantidad_edges = 0, forrest = 0;
        letters.assign(26,0);
        while (1){
            cin >> edge;
            if (edge[0] == '*') break;
            letters[edge[1]-'A']++;
            letters[edge[3]-'A']++;
            cantidad_edges++;
        }
        cin >> edge;
        nodos = (edge.size()+1)/2;
        for (int i = 0; i < edge.size(); ++i) {
            if (edge[i] == ',') continue;
            if (!letters[edge[i]-'A']) acorn++;
        }
        forrest = nodos - cantidad_edges - acorn;
        cout << "There are " << forrest << " tree(s) and "<< acorn << " acorn(s).\n";
    }
}