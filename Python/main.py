#from BFS import BFS
from FordFulkerson import FordFulkerson

#def BFSReadTxt():
#    filename = "input_txts/BFS_adjMatrix.txt"
#    adjMatrix = []
#    with open(filename, 'r') as file:
#        lines = file.readlines()
#        n = int(lines[0])
#        for i in range(1, n+1):
#            adjMatrix.append(lines[i].split())
#        weights = lines[n+1].split()
#    for i in range(n):
#        adjMatrix[i] = [int(adjMatrix[i][j]) for j in range(n)]
#    weights = [int(weights[i]) for i in range(n)]
#    return n, adjMatrix, weights


def BFSReadTxt():
    filename = "input_txts/BFS_adjMatrix.txt"
    adjMatrix = []
    with open(filename, 'r') as file:
        lines = file.readlines()
        n = int(lines[0])
        for i in range(1, n+1):
            adjMatrix.append(lines[i].split())
    for i in range(n):
        adjMatrix[i] = [int(adjMatrix[i][j]) for j in range(n)]
    return n, adjMatrix


def FFReadTxt():
    filename = "input_txts/FF_adjMatrix.txt"
    adjMatrix = []
    with open(filename, 'r') as file:
        lines = file.readlines()
        n = int(lines[0])
        for i in range(1, n+1):
            adjMatrix.append(lines[i].split())
    for i in range(n):
        adjMatrix[i] = [float(adjMatrix[i][j]) for j in range(n)]
    return n, adjMatrix


def main():
    n, adjMatrix = FFReadTxt()
    flowMatrix = FordFulkerson(n, adjMatrix, 0, 3)
    for i in range(n):
        for j in range(n):
            print(f"{flowMatrix[i][j]:8.2f}", end=" ")
        print("")

main()