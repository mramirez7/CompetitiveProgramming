//SEGMENT TREE INDEXDADO EN 0, RANGOS INCLUSIVOS

N = 100000;
int segment_tree[N*4];
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x) - 1; }
int reserved, n, neutro = 1; //MODIFICAR NEUTRO

int query_(int p,int q, int l, int r, int index){
    if (p == l && q == r) return segment_tree[index];
    if (q <= (r+l)/2) return query_(p, q, l, (r+l)/2, 2*index+1); //left child
    else if (p > (r+l)/2) return query_(p,q, 1+(r+l)/2, r, 2*index+2); //right child
    else return query_(p,(r+l)/2, l, (r+l)/2, 2*index+1)*query_(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2); //CAMBIAR SEGUN OPERACION
}
int query(int p, int q){
    return query_(p, q, 0, reserved, 0);
}

void update(int index, int value){
    index += reserved;
    segment_tree[index] = value;
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
    int n;
    int p, q;
    p = 1; q = 2;
    //example
    update(p, q);
    int ans = query(p,q); //query de p a q inclusive
}
