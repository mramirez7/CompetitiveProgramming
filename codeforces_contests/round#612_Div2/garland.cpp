#include <bits/stdc++.h>
using namespace std;

vector <int> numb;

int main(){
    int n, aux, even = 0, odd, whole = 0, whole_size, paridad = -1, ans = 0, left_whole_size=0, right_whole_size=0, left_parity=2, right_parity=2;
    priority_queue <int> qe;
    priority_queue <int> qo;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        if (aux && !(aux%2)) even++;
        if (!aux) whole++;
        numb.push_back(aux);
    }
    odd = n - whole - even;
    even = n/2 - even;
    odd = (n+1)/2 - odd;
    if (n/2 == even && (n+1)/2 == odd && n > 1) {
        cout << "1\n";
        return 0;
    }
    whole_size = 0;
    int flag = 1;
    for (int j = 0; j < n; ++j) {
        if (numb[j] == 0) whole_size++;
        else {
            if (whole_size && (paridad == -1 || paridad == numb[j]%2)) {
                if (flag) {left_whole_size = whole_size; left_parity = numb[j]%2; }//q.push({-whole_size, numb[j]%2 - 2});
                else {
                    if (numb[j]%2) qo.push(-whole_size);
                    else qe.push(-whole_size);
                }
                flag = 0;
            }
            else if (whole_size) ans++;
            paridad = numb[j]%2;
            whole_size = 0;
            flag = 0;
        }
        if (j && numb[j] != 0 && numb[j-1] != 0 && numb[j]%2 != numb[j-1]%2) ans++;
    }
    if (whole_size) {right_whole_size = whole_size; right_parity = paridad; }//q.push({-whole_size, paridad - 2});
    qe.push(-INT_MAX/4);
    qo.push(-INT_MAX/4);
    while (qe.size()){
        whole_size = -qe.top();
        if (even >= whole_size) even -= whole_size;
        else {
            ans += 2 * (qe.size()-1);
            if (!left_parity && !right_parity) {
                if (min(left_whole_size, right_whole_size) > even) ans += 2;
                else if (left_whole_size + right_whole_size > even) ans++;
            } else if (!left_parity) {
                if (left_whole_size > even) ans++;
            }else if (!right_parity) {
                if (right_whole_size > even) ans++;
            }
            break;
        }
        qe.pop();
    }
    while (qo.size()){
        whole_size = -qo.top();
        if (odd >= whole_size) odd -= whole_size;
        else {
            ans += 2 * (qo.size()-1);
            if (left_parity == 1 && right_parity == 1) {
                if (min(left_whole_size, right_whole_size) > odd) ans += 2;
                else if (left_whole_size + right_whole_size > odd) ans++;
            } else if (left_parity == 1) {
                if (left_whole_size > odd) ans++;
            }else if (right_parity == 1) {
                if (right_whole_size > odd) ans++;
            }
            break;
        }
        qo.pop();
    }
    cout << ans << "\n";
}