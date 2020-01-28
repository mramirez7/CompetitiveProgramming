#include <bits/stdc++.h>
using namespace std;

vector <int> ocupadas;
int casas[200000];

int main(){
    int n, ans_min = 0, ans_max = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> casas[i];
    }
    ocupadas.assign(n+2,0);
    sort(casas, casas+n);
    for (int j = 0; j < n; ++j) {
        if (ocupadas[casas[j]-1] || ocupadas[casas[j]] || ocupadas[casas[j]+1]) continue;
        else {
            ocupadas[casas[j]+1] = 1;
            ans_min++;
        }
    }
    cout << ans_min << " ";
    ocupadas.assign(n+2,0);
    for (int j = 0; j < n; ++j) {
        if (!ocupadas[casas[j]-1]){
            ocupadas[casas[j]-1] = 1;
            ans_max++;
        }else if (!ocupadas[casas[j]]){
            ocupadas[casas[j]] = 1;
            ans_max++;
        }else if (!ocupadas[casas[j]+1]){
            ocupadas[casas[j]+1] = 1;
            ans_max++;
        }
    }
    cout << ans_max << "\n";
    return 0;
}