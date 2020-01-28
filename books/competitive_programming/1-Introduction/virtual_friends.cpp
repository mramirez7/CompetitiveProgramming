#include <bits/stdc++.h>
using namespace std;

map <string, int> mapeo;
vector <int> rep;
vector <int> tamano;

int find(int x){
    if (rep[x] != x){
        rep[x] = find(rep[x]);
    }
    return rep[x];
}

void union_(int x, int y){
    //y es representante del otro conjunto
    int siguiente;
    while (1){
        if (x == rep[x]){
            rep[x] = y;
            break;
        }
        siguiente = rep[x];
        rep[x] = y;
        x = siguiente;
    }
}

int main() {
    int n, m, people, person1, person2, rep1, rep2;
    string p1,p2;
    cin >> n;
    while (n--){
        rep.clear();
        tamano.clear();
        mapeo.clear();
        cin >> m;
        people = 0;
        while (m--){
            cin >> p1 >> p2;
            if (mapeo.find(p1) == mapeo.end()){
                 mapeo.insert({p1,people});
                 rep.push_back(people);
                 tamano.push_back(1);
                 people++;
            }
            if (mapeo.find(p2) == mapeo.end()){
                mapeo.insert({p2,people});
                rep.push_back(people);
                tamano.push_back(1);
                people++;
            }
            person1 = mapeo.find(p1)->second;
            person2 = mapeo.find(p2)->second;
            rep1 = find(person1);
            rep2 = find(person2);
            if (rep1 == rep2){
                cout << tamano[rep1] << "\n";
            }
            else{
                cout << tamano[rep1] + tamano[rep2] << "\n";
                union_(person1, rep2);
                tamano[rep2] += tamano[rep1];
            }
        }
    }
}