#include <bits/stdc++.h>
using namespace std;

vector <int> values;
vector <int> bit1;
vector <int> bit2;
int neutro = 1;

void build_fenwick1(){
    for (int i = 1; i < values.size(); ++i) {
        int aux = i&-i;
        for (int j = i; aux > 0; j--) {
            aux--;
            if (values[j]) bit1[i] *= values[j];
        }
    }
}
void build_fenwick2(){
    for (int i = 1; i < values.size(); ++i) {
        int aux = i&-i;
        for (int j = i; aux > 0; j--) {
            aux--;
            if (!values[j]) bit2[i]++;
        }
    }
}

int query_2(int x){
    int ans = 0;
    for (int i = x; i ; i -= i&-i) {
        ans += bit2[i];
    }
    return ans;
}

int query2(int x, int y){
    if (x-1) return query_2(y) - query_2(x-1);
    return query_2(y);
}

int query_1(int x){
    int ans = 1;
    for (int i = x; i ; i -= i&-i) {
        ans *= bit1[i];
    }
    return ans;
}

int query1(int x, int y){
    if (x-1) return query_1(y)/query_1(x-1);
    return query_1(y);
}

void update_1(int index, int value){
    int q = query1(index, index);
    if (q != value){
        while (index < bit1.size()){
            bit1[index] *= -1;
            index += index&-index;
        }
    }
}

void update_2(int index, int value){
    int q = query2(index, index);
    if (!(value && !q)){
        if (!value) value = 1;
        else value = -1;
        while (index < bit2.size()){
            bit2[index] += value;
            index += index&-index;
        }
    }
}

int main(){
    int n, k, index, v, value;
    char op;
    while (cin >> n >> k) {
        bit1.assign(n + 1, neutro);
        bit2.assign(n + 1, 0);
        values.clear();
        values.push_back(1);
        for (int i = 1; i <= n; ++i) {
            cin >> v;
            if (v > 0)v = 1;
            if (v < 0)v = -1;
            values.push_back(v);
        }
        build_fenwick1();
        build_fenwick2();

        for (int j = 0; j < k; ++j) {
            cin >> op >> index >> v;
            if (op == 'C') {
                if (v > 0) v = 1;
                if (v < 0) v = -1;
                update_1(index, v);
                update_2(index, v);
            } else {
                if (query2(index, v)) cout << 0;
                else {
                    if (query1(index, v) > 0) cout << "+";
                    else cout << "-";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}