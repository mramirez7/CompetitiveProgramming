#ACCEPTED
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

t = int(input())
while t:
    t -= 1
    length, n = [int(x) for x in input().split(" ")]
    words = []
    for _ in range(n): words.append(input().strip())
    ans = length*n
    for i in range(1,n):
        ans -= kmp_preprocess(words[i-1][::-1]+"$"+words[i][::-1])
    print (ans)


