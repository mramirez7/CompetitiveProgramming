#include <bits/stdc++.h>
using namespace std;

vector <int> back;

int kmp_preprocess(string s){
    //cout << s << "\n";
    int i = 0, j = -1;
    back.reserve(s.size()+1); back[0] = -1;
    while (i < s.size()){
        while (j >= 0 && s[i] != s[j]) j = back[j];
        i++; j++; back[i] = j;
    }
    return back[s.size()-1];
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

int main(){
    int t, k;
    string w, r, d;
    cin >> t;
    while (t--) {
        cin >> w;
        r = w;
        reverse(r.begin(), r.end());
        int pp = kmp_preprocess(w+"#"+r)+1;
        int sp = kmp_preprocess(r+"#"+w)+1;
        int dd;
        int i = 0, j = w.size()-1;
        while (w[i] == w[j] && i < j){
            i++;
            j--;
        }
        int aa = 0, bb = 0;
        if (i == j) dd = i*2 + w.size()%2;
        else if (i > j) dd = 2*i;
        else {
            dd = 2 * i;
            string a = w.substr(i, w.size()-2*i);
            string b = a;
            reverse(b.begin(), b.end());
            aa = kmp_preprocess(a+"#"+b)+1;
            bb = kmp_preprocess(b+"#"+a)+1;
        }
        if (pp == w.size()){
            cout << w << "\n";
        }else if (pp >= sp && pp >= dd + aa && pp >= dd + bb){
            cout << w.substr(0, pp) << "\n";
        }else if (sp >= pp && sp >= dd + aa && sp >= dd + bb) {
            cout << w.substr(w.size()-sp, sp) << "\n";
        }else if (dd+aa >= dd+bb){
            cout << w.substr(0, i+aa) << w.substr(w.size()-i, i) << "\n";
        }
        else{
            cout << w.substr(0, i) << w.substr(w.size()-i-bb) << "\n";
        }
    }
}