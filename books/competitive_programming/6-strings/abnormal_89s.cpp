//ACCEPTED
//TAGS: KMP
#include <bits/stdc++.h>
using namespace std;

vector <int> back;

void kmp_preprocess(string s){
    int i = 0, j = -1;
    back.reserve(s.size()+1); back[0] = -1;
    while (i < s.size()){
        while (j >= 0 && s[i] != s[j]) j = back[j];
        i++; j++; back[i] = j;
    }
}

int kmp_search(string t, string p){
    int i = 0, j = 0;
    while (i < t.size()){
        while (j >= 0 && t[i] != p[j]) j = back[j];
        i++; j++;
        if (j == p.size()) return i-j;
    }
    return -1;
}

int main() {
    int t, k;
    string w, r, d;
    cin >> t;
    while (t--) {
        cin >> w;
        r = w;
        reverse(r.begin(), r.end());
        kmp_preprocess(r);
        d = "";
        for (int i = 1; i < 2*w.size(); ++i) {
            d += w[i%w.size()];
        }
        k = kmp_search(d,r);
        if (k!=-1 && k+1 != w.size())
            cout << "alindrome\n";
        else if (k !=-1)
            cout << "palindrome\n";
        else
            cout << "simple\n";
    }
}