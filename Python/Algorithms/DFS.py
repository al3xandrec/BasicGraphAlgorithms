def DFS(n, adjMatrix, *args):
    color = ["WHITE"]*n
    pi = [-1]*n
    time = 0
    d = [-1]*n
    f = [-1]*n

    print(len(args))

    def DFSVisit(u):
        nonlocal color
        nonlocal time
        nonlocal d
        nonlocal f
        nonlocal pi

        color[u] = "GRAY"
        time = time+1
        d[u] = time
        for v in range(n):
            if adjMatrix[u][v] == 1 and color[v] == "WHITE":
                pi[v] = u
                DFSVisit(v)
        color[u] = "BLACK"
        time = time+1
        f[u] = time

    if len(args) == 1:
        DFSVisit(args[0])
    else:
        for u in range(n):
            if color[u] == "WHITE":
                DFSVisit(u)
    
    return d, f, pi
