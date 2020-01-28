def kmp_preprocess(s):
    i = 0
    j = -1
    b = [0 for _ in range(len(s)+1)]
    b[0] = -1
    while i < len(s):
        while j >= 0 and s[i] != s[j]: j = b[j]
        i += 1
        j += 1
        b[i] = j
    return b
t = int(input())
while t:
    t -= 1
    s = input().strip()
    s = input().strip()
    if (s == '.'): break
    kmp = kmp_preprocess(s)
    r = max([p - kmp[p] for p in range(len(kmp))])
    if len(s)%r: print(len(s))
    else: print(r)
    if t: print("")