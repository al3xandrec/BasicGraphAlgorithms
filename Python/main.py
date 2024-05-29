#from FordFulkerson import FordFulkerson
#from BFS import BFS
#from DFS import DFS
from PlotGraph import *
from ReadTxt import *


def main():
    n, adjMatrix = UnweightedReadTxt()

    #d, pi = BFS(n, adjMatrix, 0)

    n = 3
    adjMatrix = [
        [0, 1, 2],
        [1, 0, 3],
        [2, 3, 0]
    ]


    #print(d)
    #print(f)
    #print(pi)

    PlotGraph(n, adjMatrix)

main()