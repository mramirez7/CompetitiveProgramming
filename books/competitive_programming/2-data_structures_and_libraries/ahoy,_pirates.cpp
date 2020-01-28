//ME QUEDÓ ENGORROSO CON EL LAZY RIP POR AHORA
#include <bits/stdc++.h>
using namespace std;

int neutro = 0;
vector <int> segment_tree;
vector <int> lazy;
vector <int> lazy_time;
vector <int> invert;
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x) - 1; }
int reserved, n, time_;
string pirates;

void  lazy_update_(int p, int q, int l, int r, int index, int value){
    if (p == l && q == r) {
        lazy[index] = value; //SEGUN OPERACION
        lazy_time[index] = time_;
    }else if (q <= (r+l)/2) {
        lazy_update_(p, q, l, (r+l)/2, 2*index+1, value); //left child
    }
    else if (p > (r+l)/2){
        lazy_update_(p,q, 1+(r+l)/2, r, 2*index+2, value); //right child
    } else {
        lazy_update_(p,(r+l)/2, l, (r+l)/2, 2*index+1, value);
        lazy_update_(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2, value); //NOPE //CAMBIAR SEGUN OPERACION
    }
}

void lazy_update(int p, int q, int value){
    lazy_update_(p, q, 0, reserved, 0, value);
}

int query_(int p,int q, int l, int r, int index){
    if (p == l && q == r) {
        if (!lazy[index]) return segment_tree[index];
        if (lazy[index] == 1) return r-l+1;
        if (lazy[index] == 2) return 0;
        if (lazy[index] == 3) return r-l+1 - segment_tree[index];
    }
    if (lazy[index] == 1){
        segment_tree[index] = lazy[index]*(r-l+1);
    } else if (lazy[index] == 2){
        segment_tree[index] = 0;
    } else if (lazy[index] == 3){
        segment_tree[index] = r-l+1-segment_tree[index];
    }
    if (lazy[index]){
        lazy[index*2+1] = lazy[index];
        lazy[index*2+2] = lazy[index];
        lazy[index] = neutro;
    }
    if (q <= (r+l)/2) return query_(p, q, l, (r+l)/2, 2*index+1); //left child
    else if (p > (r+l)/2) return query_(p,q, 1+(r+l)/2, r, 2*index+2); //right child
    else return query_(p,(r+l)/2, l, (r+l)/2, 2*index+1)+query_(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2); //CAMBIAR SEGUN OPERACION
}
int query(int p, int q){
    return query_(p, q, 0, reserved, 0);
}

void build_segment_tree(int n){
    int e = log2(n);
    if (__builtin_popcount(n) != 1) e++;
    reserved = 1 << e;
    reserved--; //espacio reservado para resto del arbol
    for (int i = reserved; i < 2*reserved+1; i++) { //se carga el arreglo inicial. cambiar cin por arreglo
        if (i - reserved < n) segment_tree[i] = pirates[i-reserved]-'0';
        else segment_tree[i] = neutro; //rellena con neutro hasta la potencia de 2 mas cercana
    }
    for (int k = reserved-1; k >= 0; k--) { //se instancia el segment tree completo
        segment_tree[k] = segment_tree[2*k+1]+segment_tree[2*k+2]; //CAMBIAR SEGUN OPERACION
    }
}

int main(){//lazy = 1, todos son 1. lazy = 2. todos son 0. lazy = 3. todos están invertidos
    int T, N, M, R, Q, a, b;
    string aux, action;
    cin >> T;
    while (T--){
        time_ = 0;
        segment_tree.clear();
        lazy.clear();
        lazy_time.clear();
        invert.clear();
        cin >> M;
        pirates = "";
        for (int i = 0; i < M; ++i) {
            cin >> R >> aux;
            for (int j = 0; j < R; ++j) {
                pirates += aux;
            }
        }
        segment_tree.reserve(pirates.size()*4);
        lazy.assign(pirates.size()*4, neutro);
        invert.assign(pirates.size()*4, neutro);
        lazy_time.reserve(pirates.size()*4);
        build_segment_tree(pirates.size());
        cin >> Q;
        for (int k = 0; k < Q; ++k) {
            cin >> action >> a >> b;
            if (action[0] == 'F') {
                lazy_update(a, b, 1);
                lazy_update(0,3, 2);
                cout << query(a, b) << "as\n";
                time_++;
                return 0;
            }
            else if (action[0] == 'E') {
                lazy_update(a, b, 2);
                time_++;
                cout << query(a, b) << "E\n";
            }
            else if (action[0] == 'I')
                for (int i = a; i <= b; ++i) {
                    if (query(i,i)) lazy_update(i,i,3);
                    else lazy_update(i,i, 1);
                }
            else if (action[0] == 'S')
                cout << query(a,b) << "\n";
        }
    }
    return 0;
}