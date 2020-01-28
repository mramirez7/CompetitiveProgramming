//ACCEPTED

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

int find_rep(int x, int *rep){
    if (rep[x] != x){
        rep[x] = find_rep(rep[x], rep);
    }
    return rep[x];
}

void unir(int x, int y, int *rep){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int cant_elementos, cant_operaciones;
    cin >> cant_elementos >> cant_operaciones;
    int representantes[cant_elementos+1];
    for (int k = 0; k < cant_elementos; ++k) {
        representantes[k] = k;
    }
    string operacion;
    int elem_1, elem_2;
    int rep_1, rep_2;
    for (int i = 0; i < cant_operaciones; i++) {
        cin >> operacion;
        cin >> elem_1 >> elem_2;
        rep_1 = find_rep(elem_1, representantes);
        rep_2 = find_rep(elem_2, representantes);
        if (operacion == "="){
            if (rep_1 != rep_2){
                unir(elem_1, rep_2, representantes);
            }
        } else {
            if (rep_1!=rep_2){
                printf("no\n");
            } else {
                printf("yes\n");
            }
        }
    }
    return 0;
}