def dfs(s, vis, notvis):
    notvis.remove(s[-1])
    vis.add(s[-1])
    if (len(s) == len(st)):
        ans.add(s)
        return
    for a in notvis:
        flag = 1
        for i in g[a]:
            if i not in vis:
                flag = 0
                break
        if flag: dfs(s+a, vis.copy(), notvis.copy())
    return

t = int(input())
flag = False
while (t):
    input()
    t -= 1
    in_ = input().strip()
    if flag: print ()
    else: flag = True
    ans = set()
    st = set(in_.split())
    g = {A: [] for A in st}
    in_ = input().strip()
    i = 0
    while i < len(in_):
        g[in_[i+2]].append(in_[i])
        i += 4
    for b in st:
        if (len(g[b])): continue
        dfs(b, set(), st.copy())
    if len(ans):
        ans = list(ans)
        ans.sort()
        for c in ans:
            print(" ".join(c))
    else: print("NO")