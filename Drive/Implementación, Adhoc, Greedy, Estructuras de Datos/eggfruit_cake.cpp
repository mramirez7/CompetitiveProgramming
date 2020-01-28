//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    string cake;
    int s, len;
    long long slices = 0;
    queue <int> ee;
    cin >> cake >> s;
    len = cake.size();
    cake = cake + cake;
    for (int i = 0; i < s; i++) {
        if (cake[i] == 69) ee.push(i);
    }
    for (int j = 0; j < len ; j++) {
        if (j > ee.front() && ee.size()) ee.pop();
        if (ee.size()) slices += s - (ee.front()-j);
        if (cake[j+s] == 69) ee.push(j+s);
    }
    cout << slices << "\n";
}


