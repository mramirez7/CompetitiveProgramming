#ACCEPTED
while 1:
    flag = 1
    s = input()
    if (s == "*"): break
    words = s.split(" ")
    for w in words:
        if (w[0].lower() != words[0][0].lower()):
            flag = 0
            break
    if flag: print("Y")
    else: print("N")