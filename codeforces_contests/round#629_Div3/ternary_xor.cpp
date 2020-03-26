#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector<vi> vvi;

int main(){
    int t, n;
    string a, b, c;
    cin >> t;
    while (t--){
        cin >> n >> a;
        b = "";
        c = "";
        int flag = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == '2' && flag){
                b += "0";
                c += "2";
            }else if (a[i] == '2'){
                b += "1";
                c += "1";
            }if (a[i] == '1' && flag){
                b += "0";
                c += "1";
            }else if (a[i] == '1'){
                b += "1";
                c += "0";
                flag = 1;
            }if (a[i] == '0'){
                b += "0";
                c += "0";
            }
        }
        cout << b << "\n" << c << "\n";
    }
}