//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

long double EPS = 1E-11;

struct team{
    int solved = 0;
    int penalty = 0;
    int wrong_attemps = 0;
};

int main(){
    int t, p, attemps, att, pen, flag;
    string reader;
    while (cin >> t >> p){
        vector <team> teams;
        teams.clear();
        teams.assign(t, {0,0,0});
        if (!(t|p)) return 0;
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < p; ++j) {
                cin >> reader;
                att = 0;
                pen = 0;
                flag = 1;
                for (int k = 0; k < reader.size(); ++k) {
                    if (reader[k] == '/'){
                        flag = 0;
                        continue;
                    }
                    if (flag){
                        att *= 10;
                        att += (reader[k] -'0');
                    }else{
                        if (reader[k] == '-') {
                            pen = -1;
                            break;
                        }
                        pen *= 10;
                        pen += (reader[k] -'0');
                    }
                }
                if (pen != -1) {
                    teams[i].solved++;
                    teams[i].penalty += pen;
                    teams[i].wrong_attemps += att-1;
                }
            }
        }
        int max_ = INT_MAX;
        int min_ = 1;
        double aux;
        for (int l = 0; l < t; ++l) {
            for (int i = l+1; i < t; ++i) {
                    if (teams[l].solved != teams[i].solved) continue;
                    if (teams[l].wrong_attemps == teams[i].wrong_attemps) continue;
                    aux = (1.0*(teams[i].penalty-teams[l].penalty))/(1.0*(teams[l].wrong_attemps - teams[i].wrong_attemps));
                    if (aux < 0) continue;

                    if (aux <= 20 + EPS && aux >= 20 - EPS) {max_ = 20; min_ = 20;}
                    else if (aux > 20) aux -= EPS;
                    else if (aux < 20) aux += EPS;

                    if (fabs(aux) > 20) max_ = min(abs((int)aux), max_);
                    else if(fabs(aux) < 20) min_ = max(abs((int)(aux+1)), min_);
            }
        }

        cout << min_ << " ";
        if (max_ == INT_MAX) cout << "*\n";
        else cout << max_ << "\n";
    }
}