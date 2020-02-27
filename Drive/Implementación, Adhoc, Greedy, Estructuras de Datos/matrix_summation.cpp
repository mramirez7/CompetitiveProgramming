//ACCEPTED

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> bit_2D;
int n;

int total(int x, int y){
    int ans = 0;
    int ty;
    while (x){
        ty = y;
        while (ty){
            ans += bit_2D[x][ty];
            ty -= (ty&-ty);
        }
        x -= (x&-x);
    }
    return ans;
}

int query(int x1, int y1, int x2, int y2){
    return total(x2, y2)-total(x1-1, y2) - total(x2, y1-1) + total(x1-1, y1-1);
}

void update(int x, int y, int v){
    int ty;
    while (x <= n){
        ty = y;
        while (ty<=n){
            bit_2D[x][ty] += v;
            ty += (ty&-ty);
        }
        x += (x&-x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int c;
    int x1, y1, x2, y2, v;
    string op;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> n;
        bit_2D.clear();
        bit_2D.assign(n+1, vector<int>());
        for (int j = 0; j < n+1; j++) {
            bit_2D[j].assign(n+1, 0);
        }
        while (1){
            cin >> op;
            if (op[0] == 69) break;
            else if (op[1] == 69){
                cin >> x1 >> y1 >> v;
                x1++; y1++;
                update(x1, y1, -1*query(x1,y1,x1,y1));
                update(x1, y1, v);
            }else{
                cin >> x1 >> y1 >> x2 >> y2;
                x1++; y1++; x2++; y2++;
                cout << query(x1, y1, x2, y2) << "\n";
            }
        }
    }
}