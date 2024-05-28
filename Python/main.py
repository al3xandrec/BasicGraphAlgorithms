#from BFS import BFS
#from FordFulkerson import FordFulkerson
from DFS import DFS
from ReadTxt import *


def main():
    n, adjMatrix = UnweightedReadTxt()

    d, f, pi = DFS(n, adjMatrix)


    print(d)
    print(f)
    print(pi)

main()