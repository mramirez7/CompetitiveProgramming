#ACCEPTED
fibonacci = {1: 0, 2: 1, 3: 2, 5: 3, 8: 4, 13: 5, 21: 6, 34: 7, 55: 8, 89: 9, 144: 10, 233: 11, 377: 12, 610: 13, 987: 14, 1597: 15, 2584: 16, 4181: 17, 6765: 18, 10946: 19, 17711: 20, 28657: 21, 46368: 22, 75025: 23, 121393: 24, 196418: 25, 317811: 26, 514229: 27, 832040: 28, 1346269: 29, 2178309: 30, 3524578: 31, 5702887: 32, 9227465: 33, 14930352: 34, 24157817: 35, 39088169: 36, 63245986: 37, 102334155: 38, 165580141: 39, 267914296: 40, 433494437: 41, 701408733: 42, 1134903170: 43, 1836311903: 44}
t = int(input())
while t:
    t -= 1
    n = int(input())
    numbers = [int(x) for x in input().strip().split(" ")]
    max_a = max(numbers)
    decipher = [" " for _ in range(fibonacci[max_a]+1)]
    cipher = input().strip()
    p = 0
    for k in cipher:
        if (k.isalpha() and k.isupper()):
            decipher[fibonacci[numbers[p]]] = k
            p += 1
            if p == n: break
    print ("".join(decipher))
