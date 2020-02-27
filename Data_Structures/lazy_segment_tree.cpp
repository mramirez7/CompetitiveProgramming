#include <bits/stdc++.h>
using namespace std;

int N = 49995000, neutro = 1;
vector <int> segment_tree;
vector <int> lazy;
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x) - 1; }
int reserved, n;

void  lazy_update_(int p, int q, int l, int r, int index, int value){
    if (p == l && q == r) {
        lazy[index] *= value; //SEGUN OPERACION
    }else if (q <= (r+l)/2) {
        lazy_update_(p, q, l, (r+l)/2, 2*index+1, value); //left child
    }
    else if (p > (r+l)/2){
        lazy_update_(p,q, 1+(r+l)/2, r, 2*index+2, value); //right child
    } else {
        lazy_update_(p,(r+l)/2, l, (r+l)/2, 2*index+1, value);
        lazy_update_(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2, value); //CAMBIAR SEGUN OPERACION
    }
}

void lazy_update(int p, int q){
    lazy_update_(p, q, 0, reserved, 0, -1);
}

int query_(int p,int q, int l, int r, int index){
    if (p == l && q == r) return segment_tree[index]*lazy[index]; //CAMBIAR SEGUN OPERACION
    segment_tree[index] *= lazy[index];
    lazy[index*2+1] *= lazy[index];
    lazy[index*2+2] *= lazy[index];
    lazy[index] = neutro;
    if (q <= (r+l)/2) return query_(p, q, l, (r+l)/2, 2*index+1); //left child
    else if (p > (r+l)/2) return query_(p,q, 1+(r+l)/2, r, 2*index+2); //right child
    else return query_(p,(r+l)/2, l, (r+l)/2, 2*index+1)*query_(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2); //CAMBIAR SEGUN OPERACION
}
int query(int p, int q){
    return query_(p, q, 0, reserved, 0);
}

void update(int index){
    index += reserved;
    segment_tree[index] *= -1;
    index = (index-1)/2;
    while (index){
        if (segment_tree[index] == segment_tree[index*2+1]*segment_tree[index*2+2]) break; //CAMBIAR SEGUN OPERCION
        segment_tree[index] = segment_tree[index*2+1]*segment_tree[index*2+2]; //CAMBIAR SEGUN OPERACION
        index = (index-1)/2;
    }
    segment_tree[index] = segment_tree[index*2+1]*segment_tree[index*2+2]; //CAMBIAR SEGUN OPERACION
}

void build_segment_tree(int n){
    int e = log2(n);
    if (__builtin_popcount(n) != 1) e++;
    reserved = 1 << e;
    reserved--; //espacio reservado para resto del arbol
    for (int i = reserved; i < 2*reserved+1; i++) { //se carga el arreglo inicial. cambiar cin por arreglo
        if (i - reserved < n) segment_tree[i] = 1;
        else segment_tree[i] = neutro; //rellena con neutro hasta la potencia de 2 mas cercana
    }
    for (int k = reserved-1; k >= 0; k--) { //se instancia el segment tree completo
        segment_tree[k] = segment_tree[2*k+1]*segment_tree[2*k+2]; //CAMBIAR SEGUN OPERACION
    }
}

int main(){
    int m, q, f1, f2, k, pos;
    cin >> n >> m >> q;
    segment_tree.reserve((n*(n-1))*2);
    lazy.assign((n*(n-1))*2, 1);
    build_segment_tree((n*(n-1))/2);
    for (int i = 0; i < m; ++i) {
        cin >> k >> f1 >> f2;
        f1--; f2--;
        pos = coord_transform(f1,f2);
        lazy_update(pos, pos+k-1);
    }
    for (int j = 0; j < q; ++j) {
        cin >> f1 >> f2;
        f1--; f2--;
        if (f1 > f2) swap(f1,f2);
        pos = coord_transform(f1,f2);
        if (query(pos,pos) == 1){
            cout << "NO\n";
        }else{
            cout << "SI\n";
        }
    }
}
