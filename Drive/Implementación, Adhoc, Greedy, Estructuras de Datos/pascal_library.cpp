//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

vector <int> alumnos;
int main(){
    int n, d, c, flag;
    while (cin >> n >> d){
        flag = 0;
        if (!n&&!d) return 0;
        alumnos.assign(n,1);
        for (int i = 0; i < d; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> c;
                alumnos[j] *= c;
            }
        }
        for (int k = 0; k < n; ++k) {
            if (alumnos[k]){
                flag = 1;
                break;
            }
        }
        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
}
