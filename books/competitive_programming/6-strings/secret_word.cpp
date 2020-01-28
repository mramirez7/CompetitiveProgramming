//ACCEPTED
//TAGS: KMP
#include <bits/stdc++.h>
using namespace std;

vector <int> back;
char s[2000001];
int len;

int kmp_preprocess(){
    int i = 0, j = -1, ans = 0;
    back.reserve(len+1); back[0] = -1;
    while (i < len){
        while (j >= 0 && s[i] != s[j]) j = back[j];
        i++; j++; back[i] = j;
        if (i > len/2) ans = max(ans, j);
    }
    return ans;
}

int main() {
    int t, k;
    string w, r;
    cin >> t;
    while (t--) {
        cin >> s;
        len = strlen(s);
        int i = len+1;
        s[len] = '$';
        for (int j = len-1; j >= 0; j--) {
            s[i] = s[j];
            i++;
        }
        len *= 2;
        len++;
        k = kmp_preprocess();
        for (int l = k-1; l >= 0; l--) {
            cout << s[l];
        }
        cout << "\n";
    }
}