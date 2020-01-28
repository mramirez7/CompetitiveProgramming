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
    return b[-1]

while 1:
    try:
        s = input().strip()
    except EOFError: break
    s_ = s[::-1] + "$" + s
    kmp = kmp_preprocess(s_)
    s_ = s[0:-kmp]
    print(s + s_[::-1])
