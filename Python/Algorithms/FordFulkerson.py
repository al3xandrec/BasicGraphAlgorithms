from Algorithms.BFS import BFS
INFINITY = 1000000

def Soma(a,b):
    if a == INFINITY or b == INFINITY:
        return INFINITY
    return a+b

def EvaluateResidualNetwork(n, adjMatrix, flowMatrix):
    residualNetwork = [0]*n
    for i in range(n):
        residualNetwork[i] = [0 for j in range(n)]

    for i in range(n):
        for j in range(n):
            residualNetwork[i][j] = Soma(adjMatrix[i][j],(-1)*flowMatrix[i][j])
    
    return residualNetwork

def FindSTPath(n, network, s, t):
    d, pi = BFS(n, network, s)

    if pi[t] == -1:
        return -1
    else:
        pathBackwards = []
        pathBackwards.append(t)
        index = 0
        while pi[pathBackwards[index]] != -1:
            pred = pi[pathBackwards[index]]
            index = index+1
            pathBackwards.append(pred)
        
        path = [pathBackwards[index - j] for j in range(index+1)]
        return path









def FordFulkerson(n, adjMatrix, s, t):
    flowMatrix = [0]*n
    for i in range(n):
        flowMatrix[i] = [0 for j in range(n)]

    for i in range(n):
        for j in range(n):
            if adjMatrix[i][j] > 0:
                flowMatrix[i][j] = 0
    
    residualNetwork = EvaluateResidualNetwork(n, adjMatrix, flowMatrix)
    path = FindSTPath(n, residualNetwork, s, t)
    while path != -1:
        minC = INFINITY
        for i in range(len(path)-1):
            if minC > residualNetwork[path[i]][path[i+1]]:
                minC = residualNetwork[path[i]][path[i+1]]
        for i in range(len(path)-1):
            flowMatrix[path[i]][path[i+1]] = Soma(flowMatrix[path[i]][path[i+1]], minC)
            flowMatrix[path[i+1]][path[i]] = (-1)*flowMatrix[path[i]][path[i+1]]
        residualNetwork = EvaluateResidualNetwork(n, adjMatrix, flowMatrix)
        path = FindSTPath(n, residualNetwork, s, t)

    return flowMatrix