//ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    int ans;
    int comp;
    //W=64 H=32 Q=16 E=8 S=4 T=2 X=1;
    int W=87, H=72, Q=81, E=69, S=83, T=84, X=88, sl =47;
    while (cin >> s){
        if (s.size()==1) return 0;
        ans = 0;
        comp = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == sl){
                if (comp==64) ans++;
                comp = 0;
            }
            else if(s[i]==W) comp+=64;
            else if(s[i]==H) comp+=32;
            else if(s[i]==Q) comp+=16;
            else if(s[i]==E) comp+=8;
            else if(s[i]==S) comp+=4;
            else if(s[i]==T) comp+=2;
            else if(s[i]==X) comp+=1;
        }
        cout << ans << "\n";
    }
    return 0;
}
