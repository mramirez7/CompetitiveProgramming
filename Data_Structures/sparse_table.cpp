//SPARSE TABLE RMQ
#include <bits/stdc++.h>
using namespace std;

int N;
vector <int> array;
vector <int> sparseTable;

void builldSparseTable(){
    int log_len_ceil = 32 - __builtin_clz(N);
    sparseTable.reserve(N*log_len_ceil+1);
    int potencias_2 = 2;
    for (int i = 0; i < log_len_ceil; i++) {
        potencias_2 *= 2;
        if (i == 0){
            potencias_2 = 0;
        } else if (i == 1){
            potencias_2 = 1;
        }
        for (int j = 0; j < N; ++j) {
            if (i == 0){
                sparseTable[j] = array[j];
            } else {
                sparseTable[i*N+j] = min(sparseTable[(i-1)*N + j], sparseTable[(i-1)*N + j + potencias_2]);
            }
            if (j == N - potencias_2){
                break;
            }
        }
    }
}

int query(int i, int j){ //inclusive
    if (i>j) swap(i,j);
    int log_query = 31 - __builtin_clz(j-i+1);
    int largo_query = 1 << log_query;
    return min(sparseTable[N*log_query + i], sparseTable[N*log_query + j-largo_query+1]);
}


int main(){
    int cant_queries, lim_inf, lim_sup;
    cin >> N;
    array.reserve(N+1);
    for (int i = 0; i < N; i++){
        cin >> array[i];
    }
    return 0;
}