import random
n = 20000
q = 50000
with open("../input.txt", "w") as f:
    f.write("{} {}\n".format(n,q))
    for i in range(n-1):
        u = i+2
        v = random.randint(1, i+1)
        f.write("{} {}\n".format(u,v))
    for i in range(q):
        u = random.randint(0, n-1)
        v = random.randint(0, 3)
        f.write("{} {}\n".format(u+1,v+1))


