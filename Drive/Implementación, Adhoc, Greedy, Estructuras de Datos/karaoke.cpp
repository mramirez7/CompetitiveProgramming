//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

struct event
{
    int inicio;
    int termino;
    char id;
    int sort_in;
    bool operator<(const event& rhs) const
    {
        if (sort_in)
            return inicio > rhs.inicio;
        return termino > rhs.termino;
    }
};

int main(){
    int n, s, e, ans=0;
    char c;
    priority_queue <event> salida, inicio_D, inicio_J;
    cin >> n;
    while (n--) {
        cin >> c >> s >> e;
        salida.push({s,e,c,0});
        if (c == 'D')
            inicio_D.push({s,e,c,1});
        else
            inicio_J.push({s,e,c,1});
    }
    int fin, in;
    while (salida.size()){
        c = salida.top().id;
        fin = salida.top().termino;
        in = salida.top().inicio;
        salida.pop();
        if (c == 'J'){
            if (!inicio_D.size() || inicio_D.top().inicio >= fin) continue;
            while (inicio_D.size()){
                if (inicio_D.top().termino < fin){
                    inicio_D.pop();
                    continue;
                }
                break;
            }
            if (inicio_D.size()) ans = max(ans, fin - max(inicio_D.top().inicio, in));
        }else{
            if (!inicio_J.size() || inicio_J.top().inicio >= fin) continue;
            while (inicio_J.size()){
                if (inicio_J.top().termino < fin){
                    inicio_J.pop();
                    continue;
                }
                break;
            }
            if (inicio_J.size()) ans = max(ans, fin - max(inicio_J.top().inicio, in));
        }
    }
    cout << ans << "\n";
}