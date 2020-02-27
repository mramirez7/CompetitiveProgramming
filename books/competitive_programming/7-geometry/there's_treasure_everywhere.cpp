#include <bits/stdc++.h>
using namespace std;

double x1, y11 ,x2,y2,x3,y3,x4,y4;
double EPS = 1E-12;
double diagonal = sqrt(2)/2;

struct point{
    double x, y;
};

double dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double strToDouble(string s){
    double number = 0;
    for (int i = 0; i < s.size(); ++i) {
        number *= 10.0;
        number += (s[i]-'0');
    }
    return number;
}

int main() {
    cout << setprecision(3) << fixed;
    int cont = 0;
    double move;
    string in, num, dir;
    point p;
    while (1){
        cont++;
        p.x = 0.0; p.y = 0.0;
        cin >> in;
        if (in[0] == 'E')break;

        for (int i = 0; i < in.size(); ++i) {
            if (in[i]-'0'>=0 && in[i]-'0' <= 9) num+=in[i];
            else if (in[i] != ',' && in[i] != '.') dir += in[i];
            else{
                move = strToDouble(num);
                num = "";
                if (dir.size()==1){
                    if (dir[0] == 'N') p.y += move;
                    else if (dir[0] == 'S') p.y -= move;
                    else if (dir[0] == 'E') p.x += move;
                    else p.x -= move;
                }else{
                    if (dir[0] == 'N' && dir[1] == 'E'){
                        p.x += diagonal*move;
                        p.y += diagonal*move;
                    }else if (dir[0] == 'N' && dir[1] == 'W'){
                        p.x -= diagonal*move;
                        p.y += diagonal*move;
                    }else if (dir[0] == 'S' && dir[1] == 'E'){
                        p.x += diagonal*move;
                        p.y -= diagonal*move;
                    }else{
                        p.x -= diagonal*move;
                        p.y -= diagonal*move;
                    }
                }
                dir = "";
            }
        }
        cout << "Map #" << cont << "\n";
        cout << "The treasure is located at (" << p.x << "," << p.y << ").\n";
        cout << "The distance to the treasure is " << dist(p,{0,0}) << ".\n\n";
    }
}