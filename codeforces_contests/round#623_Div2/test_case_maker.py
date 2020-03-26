import random
n = 200000
s = ""
t = ""
for i in range (n):
    if i:
        s += " "
        t += " "
    s += str(random.randint(1,2))
    t += str(random.randint(1,10**5))

with open("../in.txt", "w") as f:
    f.write(str(n) + "\n")
    f.write(s+ "\n")
    f.write(t+ "\n")