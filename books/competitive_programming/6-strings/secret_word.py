def kmp_preprocess(s):
    i = 0
    j = -1
    b = [0 for _ in range(len(s)+1)]
    b[0] = -1
    ans = 0
    while i < len(s):
        while j >= 0 and s[i] != s[j]: j = b[j]
        i += 1
        j += 1
        b[i] = j
        ans = max(ans, j)
        if i == len(s)//2: ans = 0
    print (b)
    return ans

t = int(input())
while t:
    t -= 1
    s = input().strip()
    print(s[0:kmp_preprocess(s+s[::-1])][::-1])


