#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> segment_tree;
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x) - 1; }
int reserved, n;
pair <int, int> neutro = {INT_MAX, INT_MAX}; //MODIFICAR NEUTRO

void update(int index){
    index += reserved;
    segment_tree[index].first++;
    index = (index-1)/2;
    while (index){
        if (segment_tree[index] == min(segment_tree[index*2+1],segment_tree[index*2+2])) break; //CAMBIAR SEGUN OPERCION
        segment_tree[index] = min(segment_tree[index*2+1],segment_tree[index*2+2]); //CAMBIAR SEGUN OPERACION
        index = (index-1)/2;
    }
    if (reserved) segment_tree[index] = min(segment_tree[index*2+1],segment_tree[index*2+2]); //CAMBIAR SEGUN OPERACION
}

void build_segment_tree(int n){
    int e = log2(n);
    if (__builtin_popcount(n) != 1) e++;
    reserved = 1 << e;
    reserved--; //espacio reservado para resto del arbol
    for (int i = reserved; i < 2*reserved+1; i++) { //se carga el arreglo inicial. cambiar cin por arreglo
        if (i - reserved < n) segment_tree[i] = {0, i-reserved};
        else segment_tree[i] = neutro; //rellena con neutro hasta la potencia de 2 mas cercana
    }
    for (int k = reserved-1; k >= 0; k--) { //se instancia el segment tree completo
        segment_tree[k] = min(segment_tree[2*k+1],segment_tree[2*k+2]); //CAMBIAR SEGUN OPERACION
    }
}

int main(){
    int q, x, y;
    cin >> q >> x;
    segment_tree.reserve(4*x);
    build_segment_tree(x);
    while (q--){
        cin >> y;
        y %= x;
        update(y);
        cout << segment_tree[0].first*x + segment_tree[0].second << "\n";
    }
}