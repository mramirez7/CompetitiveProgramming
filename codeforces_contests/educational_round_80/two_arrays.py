memo = [-1 for i in range(1100)]

def fac(q):
    if (memo[q] != -1): return memo[q]
    memo[q] = q*fac(q-1)
    return memo[q]

n, m = [int(x) for x in input().split()]
mod = 1000000007
memo[0] = 1
print(fac(2*m+n-1)//(fac(2*m)*fac(n-1))%mod)