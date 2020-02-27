#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y, z;
};

int dist(point p1, point p2){
    int dx = p1.x-p2.x;
    int dy = p1.y-p2.y;
    int dz = p1.z-p2.z;
    int sum = dx*dx+dy*dy+dz*dz;
    return (int)sqrt(sum);
}

vector <point> trees;
vector <int> freq;

int main() {
    int x,y,z, r;
    freq.assign(10, 0);
    while (1) {
        cin >> x >> y >> z;
        if (!(x | y | z))break;
        trees.push_back({x, y, z});
    }
    for (int i = 0; i < trees.size(); ++i) {
        r = 10;
        for (int j = 0; j < trees.size(); ++j) {
            if (i!=j) {
                r = min(dist(trees[i], trees[j]), r);
            }
        }
        if (r<10) freq[r]++;
    }
    for (int k = 0; k < 10; ++k) {
        if (freq[k] < 10) cout << "   ";
        else if (freq[k] < 100) cout << "  ";
        else if (freq[k]<1000) cout << " ";
        cout << freq[k];
    }
    cout << "\n";
}