#include <bits/stdc++.h>
using namespace std;

int numb[101];
vector <int> visited;

int main(){
    int n, even = 0, no_even = 0, ans = 0;
    cin >> n;
    visited.assign(n+1,0);
    for (int i = 0; i < n; ++i) {
        cin >> numb[i];
        numb[i]--;
        if (numb[i] != -1) visited[numb[i]] = 1;
    }
    for (int j = 0; j < n; ++j) {
        if (!visited[j]){
            if (j%2) no_even++;
            else even++;
        }
    }
    for (int l = 0; l < n-1; ++l) {
        if (numb[l] != -1 && numb[l+1] != -1 && numb[l]%2 != numb[l+1]%2) ans++;
    }
    int limite_izquierdo = 0, paridad_limite_izq = -1;
    priority_queue<pair<int, int>> cola; //ancho, paridad 0,1
    for (int k = 0; k < n; ++k) {
        if (numb[k] != -1){
            if (k > 0 && numb[k-1] == -1 && (paridad_limite_izq == numb[k]%2 || paridad_limite_izq == -1)){
                cola.push({limite_izquierdo-k, numb[k]%2});
            }else if (k > 0 && numb[k-1] == -1 && paridad_limite_izq != numb[k]%2) ans++;
            limite_izquierdo = k+1;
            paridad_limite_izq = numb[k]%2;
        }
    }
    if (numb[n-1] == -1) {
        cola.push({limite_izquierdo - n, paridad_limite_izq});
    }
    int rango, paridad;
    while (cola.size()){
        rango = cola.top().first; paridad = cola.top().second; cola.pop();
        rango = -rango;
        if (paridad && no_even >= rango) no_even -= rango;
        else if (paridad){
            ans++;
            even -= (rango-no_even);
            no_even = 0;
        }
        if (!paridad && even >= rango)even -= rango;
        else if (!paridad){
            ans++;
            no_even -= (rango-even);
            even = 0;
        }
    }
    cout << ans << "\n";
}