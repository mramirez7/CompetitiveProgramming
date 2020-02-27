//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

double EPS = 1E-10;

struct point{
    long double x, y;
};

long double norm (point p){
    return sqrt(p.x*p.x+p.y*p.y);
}

int main() {
    cout.precision(12);
    cout << fixed;
    point p, v;
    int a, b, c, d;
    long double norma;
    cin >> p.x >> p.y >> v.x >> v.y;
    cin >> a >> b >> c >> d;
    norma = norm(v);
    v.x *= 1/norma; v.y *= 1/norma;

    cout << v.x * b + p.x << " "<< v.y * b + p.y << "\n";

    cout << -v.y*a/2.0 + p.x << " " << v.x * a/2.0 + p.y << "\n";

    cout << -v.y*c/2.0 + p.x << " " << v.x * c/2.0 + p.y << "\n";

    cout << -v.y*c/2.0 - v.x*d + p.x << " " << v.x * c/2.0 - v.y*d + p.y << "\n";

    cout << v.y*c/2.0 - v.x*d + p.x << " " << -v.x * c/2.0 - v.y*d + p.y << "\n";

    cout << v.y*c/2.0 + p.x << " " << -v.x * c/2.0 + p.y << "\n";

    cout << v.y*a/2.0 + p.x << " " << -v.x * a/2.0 + p.y << "\n";
}
