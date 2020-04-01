
int t, n, mod;
long long ans = 1;
cin >> t;
n = t/1000;
mod = t%1000;
while (n > 0){
    ans *= n;
    ans %= mod;
    n -= 2;
}
cout << ans << endl;
