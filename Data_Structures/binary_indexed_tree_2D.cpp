#include <bits/stdc++.h>
using namespace std;
//2D-FENWICK TREE for sum queries
vector <vector <int>> bit_2D;
int n;

int total_sum(int x, int y){
    int ans = 0;
    for (int i = x; x ; x -= (x&-x)) {
        for (int j = y; j ; j-=(j&-j)) {
            ans += bit_2D[i][j];
        }
    }
    return ans;
}

int query(int x1, int y1, int x2, int y2){
    return total_sum(x2, y2)-total_sum(x1-1, y2) - total_sum(x2, y1-1) + total_sum(x1-1, y1-1);
}

void add_value(int x, int y, int v){ //le suma al valuesvalor actual
    for (int i = x; i <= n; i += (i&-i)) {
        for (int j = y; j <= n ; j += (j&-j)) {
            bit_2D[x][y] += v;
        }
    }
}

void update(int x, int y, int v){ //setea valor
    add_value(x, y, -1*query(x,y,x,y));
    add_value(x, y, v);
}


int main(){
    int n, x1, y1, x2, y2, v;
    cin >> n;
    bit_2D.clear();
    bit_2D.assign(n+1, vector<int>()); //asuiendo que es cuadrada
    for (int j = 0; j < n+1; j++) {    // modificar para rectángulos
        bit_2D[j].assign(n+1, 0);
    }
}
