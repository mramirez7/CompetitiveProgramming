//ACCEPTED
//TAG: DIFFERENCE ARRAY

#include <bits/stdc++.h>
using namespace std;

vector <int> friends;
int n;

int coord_transform(int i, int j){
    return (n*(j-i-1)-((j-i-1)*(j-i))/2 + i);
}

int main(){
    int m, q, f1, f2, k, pos;
    cin >> n >> m >> q;
    friends.assign((n*(n-1))/2+1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> k >> f1 >> f2;
        f1--; f2--;
        pos = coord_transform(f1,f2);
        friends[pos] += 1;
        friends[pos+k] -= 1;
    }
    for (int l = 1; l < friends.size(); ++l) {
        friends[l] += friends[l-1];
    }
    for (int j = 0; j < q; ++j) {
        cin >> f1 >> f2;
        f1--; f2--;
        if (f1 > f2) swap(f1,f2);
        pos = coord_transform(f1,f2);
        if (friends[pos] % 2){
            cout << "SI\n";
        }else{
            cout << "NO\n";
        }
    }
}
