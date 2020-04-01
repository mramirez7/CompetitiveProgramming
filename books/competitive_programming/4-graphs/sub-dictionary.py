from collections import deque

def dfs(u):
    dis[u] = cont[0]
    low[u] = cont[0]
    cont[0] += 1
    S.append(u)
    vis[u] = 1
    for v in g[u]:
        if not dis[v]:
            dfs(v)
        if vis[v]:
            low[u] = min(low[u], low[v])
    if low[u] == dis[u]:
        flag = 1
        while 1:
            v = S.pop()
            vis[v] = 0
            if not (flag and u == v): inScc[v] = 1
            flag = 0
            if (u == v):
                break

def dfs2(f):
    vis[f] = 1
    ans.add(di[f])
    for ff in g[f]:
        if not vis[ff]: dfs2(ff)
while 1:
    n = int(input())
    if not n: break
    g = [[] for i in range(n+1)]
    p = 0
    di = dict()
    dd = dict()
    for _ in range(n):
        line = input().split()
        s = line[0]
        if (s not in dd.keys()):
            dd[s] = p
            di[p] = s
            p += 1
        u = dd[s]
        for i in range(1, len(line)):
            if line[i] not in dd.keys():
                dd[line[i]] = p
                di[p] = line[i]
                p += 1
            v = dd[line[i]]
            g[u].append(v)
    inScc = [0 for _ in range(n+1)]
    low = [0 for _ in range(n+1)]
    dis = [0 for _ in range(n+1)]
    par = [0 for _ in range(n+1)]
    vis = [0 for _ in range(n+1)]
    S = deque()
    ans = set()
    cont = [1]
    for j in range(n):
        if (not dis[j]):
            dfs(j)
    vis = [0 for _ in range(n+1)]
    for k in range(n+1):
        if (not vis[k] and inScc[k]): dfs2(k)
    print(len(ans))
    ans = list(ans)
    ans.sort()
    print(" ".join(ans))