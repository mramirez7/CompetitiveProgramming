import random
n = 20000
m = 100000
q = 100000
with open("in.txt", "w") as f:
    f.write("{} {} {}\n".format(n,m,q))
    for i in range(m):
        j = random.randint(1,n-1)
        k = random.randint(j+1,n)
        m = random.randint(1, n-k+1)
        f.write("{} {} {}\n".format(m,j,k))
    for i in range(q):
        j = random.randint(1,n-1)
        k = random.randint(j+1,n)
        f.write("{} {}\n".format(j,k))