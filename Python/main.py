#from BFS import BFS
from FordFulkerson import FordFulkerson
from ReadTxt import *


def main():
    n, adjMatrix = FFReadTxt()
    flowMatrix = FordFulkerson(n, adjMatrix, 0, 3)
    for i in range(n):
        for j in range(n):
            print(f"{flowMatrix[i][j]:8.2f}", end=" ")
        print("")

main()