def dfs(u):
    dis[u] = cont[0]
    low[u] = cont[0]
    cont[0] += 1
    for v in g[u]:
        if not dis[v]:
            par[v] = u
            if (u == 1): root_childs[0] += 1
            dfs(v)
            if low[v] >= dis[u]:
                art[u] = 1
            low[u] = min(low[u], low[v])
        elif v != par[u]:
            low[u] = min(low[u], dis[v])

while 1:
    n = int(input())
    if not n: break
    g = [[] for _ in range(n+1)]
    for _ in range(n+1):
        ad = [int(x) for x in input().split()]
        u = ad[0]
        if not u: break
        for i in range(1, len(ad)):
            g[u].append(ad[i])
            g[ad[i]].append(u)
    low = [0 for _ in range(n+1)]
    dis = [0 for _ in range(n+1)]
    par = [0 for _ in range(n+1)]
    art = [0 for _ in range(n+1)]
    cont = [1]
    root_childs = [0]
    ans = [0]
    dfs(1)
    art[1] = 0
    if root_childs[0] > 1:
        art[1] = 1
    print (sum(art))
