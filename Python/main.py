#from Algorithms.FordFulkerson import FordFulkerson
#from Algorithms.BFS import BFS
#from Algorithms.DFS import DFS
#from Plot.PlotGraph import *
from Graph.Graph import *
from ReadTxt import *


def main():
    #n, adjMatrix = UnweightedReadTxt()
    
    adjMatrix = [
        [0, 1, 0],
        [1, 0, 1],
        [0, 1, 0]
    ]
    n = len(adjMatrix)

    D = Digraph(adjMatrix)
    
    D.PrintVertices()
    D.PrintEdges()

    #PlotGraph(n, adjMatrix)

main()