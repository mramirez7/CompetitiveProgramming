//WA
#include <bits/stdc++.h>
using namespace std;

map <int, int> fibonacci = {{1,0}, {2,1}, {3,2}, {5,3}, {8,4}, {13,5}, {21,6}, {34,7}, {55,8}, {89,9}, {144,10}, {233,11}, {377,12}, {610,13}, {987,14}, {1597,15}, {2584,16}, {4181,17}, {6765,18}, {10946,19}, {17711,20}, {28657,21}, {46368,22}, {75025,23}, {121393,24}, {196418,25}, {317811,26}, {514229,27}, {832040,28}, {1346269,29}, {2178309,30}, {3524578,31}, {5702887,32}, {9227465,33}, {14930352,34}, {24157817,35}, {39088169,36}, {63245986,37}, {102334155,38}, {165580141,39}, {267914296,40}, {433494437,41}, {701408733,42}, {1134903170,43}, {1836311903,44}};
vector <int> numbers;
vector <char> decipher;

int main() {
    int t, n, a, max_a;
    string cipher;
    cin >> t;
    while (t--) {
        numbers.clear();
        decipher.clear();
        max_a = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            numbers.push_back(a);
            max_a = max(max_a, a);
        }
        decipher.assign(fibonacci.find(max_a)->second + 1, ' ');
        getline(cin, cipher);
        getline(cin, cipher);
        int p = 0;
        for (int k = 0; k < cipher.size(); ++k) {
            if (cipher[k] >= 'A' && cipher[k] <= 'Z'){
                decipher[fibonacci.find(numbers[p])->second] = cipher[k];
                p++;
                if (p == n) break;
            }
        }
        for (int l = 0; l <fibonacci.find(max_a)->second + 1 ; ++l) cout << decipher[l];
        cout << "\n";
    }
}