//ACCEPTED
#include <bits/stdc++.h>
using namespace std;

set <string> dict;
vector <string> words;

int main(){
    string w, text, word;
    int max_coincidences = 0, k = 0, current_coincidences;
    while (cin >> w){
        if (w[0] == '#' && w.size() == 1) break;
        dict.insert(w);
    }
    getline(cin, text);
    getline(cin, text);
    for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < text.size()-1; ++j) {
            text[j] += 1;
            if (text[j] == 'Z' + 1) text[j] = ' ';
            if (text[j] == 33) text[j] = 'A';
        }
        current_coincidences = 0;
        word = "";

        for (int l = 0; l < text.size(); ++l) {
            if (text[l] == ' ' || text[l] == '\n'){
                if (dict.find(word) != dict.end()) current_coincidences++;
                word = "";
            } else{
                word += text[l];
            }
        }
        if (current_coincidences > max_coincidences) {
            k = i+1;
            max_coincidences = current_coincidences; current_coincidences = 0;
        }
    }
    if (k) {
        for (int j = 0; j < text.size()-1 ; ++j) {
            if (text[j] == ' ') text[j] = 'A' + k - 1;
            else {
                text[j] += k;
                if (text[j] > 'Z') text[j] -= 27;
            }
            if (text[j] == 'A'-1) text[j] = ' ';
        }
    }
    word = "";
    for (int l = 0; l < text.size()-1; ++l) {
        if (text[l] == ' ' || text[l] == '\n'){
            words.push_back(word);
            word = "";
        } else{
            word += text[l];
        }
    }
    if (word.size()) words.push_back(word);
    word = words[0];
    k = word.size();
    for (int m = 1; m < words.size(); ++m) {
        if (k + words[m].size() + 1 > 60) {
            cout << word << "\n";
            word = words[m]; k = word.size();
        }else if (m == words.size()-1) {
            cout << word << " " << words[m] << "\n";
        }else{
            word += " ";
            word += words[m];
            k += words[m].size()+1;
        }
    }
    //cout << text << "\n";
}