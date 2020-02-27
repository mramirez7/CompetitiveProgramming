#tle, accepted en c++
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

def kmp_search(t, p):
    i = 0
    j = 0
    while i < len(t):
        while j >= 0 and t[i] != p[j]: j = back[j]
        i+= 1
        j += 1
        if (j == len(p)):
            return i-j
    return -1

t = int(input())
while t:
    t -= 1
    w = input().strip()
    back = kmp_preprocess(w[::-1])
    print(back)
    al = kmp_search(w[1::]+w, w[::-1])
    if al+1 and al+1 != len(w): print("alindrome")
    elif al+1 == len(w): print ("palindrome")
    else: print ("simple")
