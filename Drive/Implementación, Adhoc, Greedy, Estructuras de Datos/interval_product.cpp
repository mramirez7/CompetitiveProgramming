//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int numbers[100000*4];
int log2(int x) { return sizeof(x) * 8 - __builtin_clz(x) - 1; }

int range_query(int p,int q, int l, int r, int index){
    if (p == l && q == r) return numbers[index];
    if (q <= (r+l)/2) return range_query(p, q, l, (r+l)/2, 2*index+1); //left child
    else if (p > (r+l)/2) return range_query(p,q, 1+(r+l)/2, r, 2*index+2); //right child
    else return range_query(p,(r+l)/2, l, (r+l)/2, 2*index+1)*range_query(1+(r+l)/2, q, 1+(r+l)/2, r, index*2+2);
}

int main(){
    int n, m;
    int p, q;
    int e, reserved, neutro = 1;
    char action;
    while (cin >> n >> m){
        e = log2(n);
        if (__builtin_popcount(n) != 1) e++;
        reserved = 1 << e;
        reserved--;
        for (int i = reserved; i < 2*reserved+1; i++) {
            if (i - reserved < n) cin >> numbers[i];
            else numbers[i] = neutro;
            if (numbers[i]) numbers[i] /= abs(numbers[i]);
        }
        for (int k = reserved-1; k >= 0; k--) {
            numbers[k] = numbers[2*k+1]*numbers[2*k+2]; //se define operacion mult
        }
        for (int j = 0; j < m; j++) {
            cin >> action >> p >> q;
            p--;
            if (action == 67){ //actualizar
                if (q) q /= abs(q);
                p += reserved;
                numbers[p] = q;
                int r_, l_;
                p = (p-1)/2;
                while (p){
                    if (numbers[p] == numbers[p*2+1]*numbers[p*2+2]) break;
                    numbers[p] = numbers[p*2+1]*numbers[p*2+2];
                    p = (p-1)/2;
                }
                numbers[p] = numbers[p*2+1]*numbers[p*2+2];
            } else { //query
                q--;
                int query = range_query(p,q, 0, reserved, 0);
                if (query == 1) cout << "+";
                else if (query == -1) cout << "-";
                else cout << 0;
            }
        }
        cout << "\n";
    }
}
