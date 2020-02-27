//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

vector <int> cards1;
vector <int> cards2;
vector <int> memo;

int dp(int cards){
    if (memo[cards] != -1) return memo[cards];
    int n_cards = 0;
    int aux = cards;
    int b = 1, ans = 0;
    vector <int> vector_cards;
    while (aux) {
        if (aux % 3 == 1) {
            n_cards++;
            vector_cards.push_back(b);
        }
        if (aux % 3 == 2){
            n_cards += 2;
            vector_cards.push_back(b);
            vector_cards.push_back(b);
        }
        aux /= 3;
        b++;
    }
    if (n_cards < 3){
        memo[cards] = 0;
        return 0;
    }
    int c1, c2, c3;
    for (int i = 0; i < n_cards; ++i) {
        c1 = vector_cards[i];
        for (int j = i+1; j < n_cards; ++j) {
            c2 = vector_cards[j];
            for (int k = j+1; k < n_cards; ++k) {
                c3 = vector_cards[k];
                if (c3 < c1+c2 && c1 > c3-c2){
                    ans = max(ans,1+ dp(cards - (int)pow(3, c1-1) - (int)pow(3, c2-1)-(int)pow(3, c3-1)));
                }
            }
        }
    }
    memo[cards] = ans;
    return ans;
}

int main(){
    int n, c, pt1, pt2, npt1, npt2;
    memo.assign(1594323, -1);
    while (cin >> n) {
        if (!n) return 0;
        cards1.assign(14,0);
        cards2.assign(14,0);
        pt1 = 0; pt2 = 0; npt1 = 0; npt2 = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c;
            if (i % 2) cards2[c]++;
            else cards1[c]++;
        }
        for (int j = 1; j < 14; ++j) {
            pt1 += cards1[j]/3;
            cards1[j] %= 3;
            pt2 += cards2[j]/3;
            cards2[j] %= 3;
        }
        if (pt1 > pt2){
            cout << "1\n";
            continue;
        }
        else if (pt1 < pt2){
            cout << "2\n";
            continue;
        }
        int b = 1;
        int cards_13 = 0;
        int cards_23 = 0;
        for (int k = 1; k <= 13; ++k) {
            cards_13 += cards1[k]*b;
            cards_23 += cards2[k]*b;
            b *= 3;
        }
        if (cards_13 == cards_23){
            cout << "0\n";
            continue;
        }
        int one = dp(cards_13);
        int two = dp(cards_23);
        if (one>two)cout << "1\n";
        else if (one<two)cout << "2\n";
        else cout << "0\n";
    }
}
