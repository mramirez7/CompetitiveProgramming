t = int(input())
while t:
    t -= 1
    ans = 1
    n = int(input())
    numbers = []
    for _ in range(n):
        numbers.append(input().strip())
    numbers.sort()
    for i in range(1, n):
        if (len(numbers[i-1]) > len(numbers[i])): continue
        for j in range(len(numbers[i-1])):
            if numbers[i-1][j] == numbers[i][j] and j == len(numbers[i-1])-1: ans = 0
            elif numbers[i-1][j] != numbers[i][j]: break
        if not ans: break
    if ans: print("YES")
    else: print("NO")