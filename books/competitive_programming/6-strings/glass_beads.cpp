//ACCEPTED
//TAG: KMP, SUFFIX ARRAY
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100010

char T[MAX_N];
int n;
int RA[MAX_N], temRA[MAX_N];
int SA [MAX_N], tempSA[MAX_N];
int c[MAX_N];
vector <int> back;

void kmp_preprocess(){
    int i = 0, j = -1;
    back.reserve(n+1); back[0] = -1;
    while (i < n){
        while (j >= 0 && T[i] != T[j]) j = back[j];
        i++; j++; back[i] = j;
    }
}

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c[i+k < n ? RA[i+k] : 0]++;
    for (i = sum = 0; i < maxi; i++){
        int t = c[i]; c[i] = sum; sum += t;}
    for (i = 0; i < n; i++)
        tempSA[c[SA[i] + k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)
        SA[i] = tempSA[i];
}

void constructSA(){
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1){
        countingSort(k);
        countingSort(0);
        temRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            temRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)
            RA[i] = temRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

int main() {
    int t, r;
    cin >> t;
    while (t--) {
        cin >> T;
        n = (int) strlen(T);
        kmp_preprocess();
        r = 0;
        for (int k = 0; k < n+1; ++k) {
            r = max(r, k - back[k]);
        }
        if (n%r) r = n;
        for (int j = 0; j < r; ++j) {
            T[j+r] = T[j];
        }
        n = 2*r;
        T[n++] = '$';
        constructSA();
        for (int i = 0; i < n; ++i) {
            if (SA[i] < (n-1)/2){
                cout << SA[i]+1 << "\n";
                break;
            }
        }
    }
}