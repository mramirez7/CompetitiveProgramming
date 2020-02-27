//ACCEPTED
//TAGS: SUFFIX ARRAY, LCP
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000

char T[MAX_N];
char S[MAX_N];
int n, m, len_lcs;
int RA[MAX_N], temRA[MAX_N];
int SA [MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];

void computeLCP(){
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++)
        Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++){
        if (Phi[i] == -1){PLCP[i] = 0; continue; }
        while (T[i+L] == T[Phi[i]+L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (i = 0; i < n; i++) {
        LCP[i] = PLCP[SA[i]];
        if (i && ((SA[i] < n-m && SA[i-1] >= n-m)||(SA[i] >= n-m && SA[i-1] < n-m))) len_lcs = max(len_lcs, LCP[i]);
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
    int flag = 0;
    while (cin >> T >> S) {
        set <string> st;
        string s;
        if (flag) cout << "\n";
        else flag = 1;
        len_lcs = 0;
        n = (int) strlen(T);
        m = (int) strlen(S);
        T[n++] = '$';
        S[m++] = '#';
        for (int j = 0; j < m; ++j) {
            T[j + n] = S[j];
        }
        n += m;
        constructSA();
        computeLCP();
        if (!len_lcs) cout << "No common sequence.\n";
        else {
            for (int i = 1; i < n; ++i) {
                if (LCP[i] == len_lcs && ((SA[i] < n-m && SA[i-1] >= n-m)||(SA[i] >= n-m && SA[i-1] < n-m))) {
                    s = "";
                    for (int j = 0; j < len_lcs; ++j) {
                        s += T[SA[i] + j];
                    }
                    if (st.find(s) == st.end()) {
                        st.insert(s);
                        cout << s << "\n";
                    }
                }
                //printf("%3d%3d\t%s\n", LCP[i], SA[i], T + SA[i]);
            }
        }
    }
}