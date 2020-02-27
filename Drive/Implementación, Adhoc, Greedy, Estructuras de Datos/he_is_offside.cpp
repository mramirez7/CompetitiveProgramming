#include <bits/stdc++.h>
using namespace std;

vector <int> defenders;
vector <int> attackers;

int main(){
    int A, D, aux;
    while (cin >> A >> D){
        if (!(A|D)) return 0;
        defenders.clear();
        attackers.clear();
        for (int i = 0; i < A; ++i) {
            cin >> aux;
            attackers.push_back(aux);
        }
        for (int j = 0; j < D; ++j) {
            cin >> aux;
            defenders.push_back(aux);
        }
        sort(attackers.begin(), attackers.end());
        sort(defenders.begin(), defenders.end());
        if (attackers[0] < defenders[1]) cout << "Y\n";
        else cout << "N\n";
    }
}
