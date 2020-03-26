long long phi(long long x){
    long long ans = x;
    for (int i = 2; (long long)i*i <= x; ++i) {
        if (x % i == 0){
            ans -= ans/i;
            while (x%i == 0) x /= i;
        }
    }
    if (x-1) ans -= ans/x;
    return ans;
}