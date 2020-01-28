//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

vector <long long int> histogram;
int left_[100001];
int right_[100001];

int main(){
    int n;
    long long int ans;
    while (1){
        cin >> n;
        if (!n) break;
        histogram.assign(n, 0);
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        left_[0] = 0;
        for (int j = 1; j < n; j++) {
            if (histogram[j]<=histogram[j-1]){
                left_[j] = left_[j-1];
                while (histogram[left_[j]-1] >= histogram[j] && left_[j]!=0) {
                    left_[j] = left_[left_[j]-1];
                }
            }
            else left_[j] = j;
        }
        right_[n-1] = n;
        for (int k = n-2; k >= 0; k--) {
            if (histogram[k] <= histogram[k+1]){
                right_[k] = right_[k+1];
                while (histogram[right_[k]] >= histogram[k] && right_[k] != n){
                    right_[k] = right_[right_[k]];
                }
            }
            else right_[k] = k+1;
        }
        for (int l = 0; l < n; l++) {
            //cout << left_[l] << " " << right_[l] << "\n";
            //cout << ans << " " << (long long int)(right_[l]-left_[l])*histogram[l] << "\n";
            ans = (long long int) max(ans, (long long int)((right_[l]-left_[l])*histogram[l]));
        }
        cout << ans << "\n";
    }
}
