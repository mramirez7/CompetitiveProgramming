#include <bits/stdc++.h>
using namespace std;

struct date{
    int day, month, year, cost;
};

bool isNextDay(date d1, date d2){
    bool isLeap = false;
    if ((d1.year == d2.year && d1.year%4 == 0 && d1.year%100 != 0) || d1.year == 2000) isLeap = true;

    if (d2.day - d1.day == 1 && d1.month == d2.month && d1.year == d2.year) return true; //dia
    if (d1.month == 2 && ((d1.day == 28 && !isLeap) || d1.day == 29 && isLeap) && d2.day == 1 && d2.month == 3 && d2.year == d1.year) return true; //mes
    if (((d1.day == 31 && (d1.month == 1 || d1.month == 3 ||d1.month == 5 || d1.month == 7 || d1.month == 8 || d1.month == 10)) || (d1.day == 30 && (d1.month == 4 || d1.month == 6 || d1.month == 9 || d1.month == 11))) && d2.day == 1 && d2.month == d1.month+1 && d1.year == d2.year) return true;
    if (d1.day == 31 && d1.month == 12 && d2.day == 1 && d2.month == 1 && d2.year - d1.year == 1) return true;//año
    return false;
}

int main(){
    int n, d, m, y, c, ans_d, ans_c;
    while (cin >> n){
        if (!n) return 0;
        ans_d = 0;
        ans_c = 0;
        vector <date> dates;
        for (int i = 0; i < n; ++i) {
            cin >> d >> m >> y >> c;
            dates.push_back({d,m,y,c});
            if (i && isNextDay(dates[i-1], dates[i])){
                ans_d++;
                ans_c += dates[i].cost - dates[i-1].cost;
            }
        }
        cout << ans_d << " " << ans_c << "\n";
    }
}