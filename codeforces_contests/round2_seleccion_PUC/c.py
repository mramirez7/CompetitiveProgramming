d = {1:"A",
     2:"B",
     3:"C",
     4:"D",
     5:"E",
     6:"F",
     7:"G",
     8:"H",
     9:"I",
     10:"J",
     11:"K",
     12:"L",
     13:"M",
     14:"N",
     15:"O",
     16:"P",
     17:"Q",
     18:"R",
     19:"S",
     20:"T",
     21:"U",
     22:"V",
     23:"W",
     24:"X",
     25:"Y",
     0:"Z",
     }


while (1):
    s = input().strip()
    if s == "R0C0": break
    a = [s.split("R")]
    n, m = a[0][1].split("C")
    m = int(m)
    r = ""
    while m > 0:
        mod = m%26
        if (not mod):
            r+= d[mod]
            m = m // 26 -1
        else:
            r+= d[mod]
            m = m//26
    print(r[::-1] + n)
