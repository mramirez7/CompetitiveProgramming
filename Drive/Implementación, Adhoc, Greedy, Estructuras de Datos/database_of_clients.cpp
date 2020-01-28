//ACCEPTED

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, pos, ans = 0;
    string mail, user, domain;
    vector <string> domains;
    vector <vector <string>> users;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mail;
        pos = mail.find("@");
        user = mail.substr(0,pos);
        domain = mail.substr(pos+1);
        pos = user.find("+");
        if (pos+1) user = user.substr(0,pos);
        pos = user.find(".");
        while (pos+1) user.erase(pos,1), pos = user.find(".");
        int flag = 0, flag_2 = 0;
        for (int j = 0; j < domains.size(); j++) {
            if (!domain.compare(domains[j])) {
                pos = j; flag = 1;
                break;}
        }
        if (flag){
            flag = 0;
            for (int j = 0; j < users[pos].size(); j++) {
                if(!user.compare(users[pos][j])) {
                    flag_2 = 1;
                    break;
                }
            }
            if (!flag_2){
                ans++;
                users[pos].push_back(user);
            }else flag_2 = 0;
        } else{
            ans++;
            users.resize(users.size()+1);
            users[users.size()-1].push_back(user);
            domains.push_back(domain);
        }
    }
    cout << ans << "\n";
}