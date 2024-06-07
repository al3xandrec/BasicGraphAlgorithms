class Vertex:
    def __init__(self, name, *args):
        self.__name = name
        if len(args) > 0:
            self.__weight = args[0]

    def __str__(self):
        try:
            return f"({self.__name}, {self.__weight})"
        except:
            return f"({self.__name})"
    
    def SetWeight(self, newWeight):
        self.__weight = newWeight
    
    def GetWeight(self):
        return self.__weight


class OrientedEdge:
    def __init__(self, name, u, v, *args):
        self.__name = name
        self.__tail = u
        self.__head = v
        if args:
            self.__weight = args[0]
    def __str__(self):
        try:
            return f"[{self.__name}({self.__tail}, {self.__head}), {self.__weight}]"
        except:
            return f"{self.__name}({self.__tail}, {self.__head})"
    
    def SetWeight(self, newWeight):
        self.__weight = newWeight
    
    def GetWeight(self):
        return self.__weight
    
    def GetHead(self):
        return self.__head
    
    def GetTail(self):
        return self.__tail
    
    def GetEdgeName(self):
        return self.__name
    

class Digraph:
    def __init__(self, *args):
        self.__numberOfVertices = 0
        self.__vertexList = []
        self.__vertexWeighted = False
        self.__edgeWeighted = False
        self.__multiEdges = False

        if type(args[0]) == type(0) and args[0] > 0: ## Init apenas com número
            self.__numberOfVertices = args[0]
            self.__adjList = [0]*self.__numberOfVertices
            for i in range(self.__numberOfVertices):
                self.__adjList[i] = []
            for i in range(self.__numberOfVertices):
                v = Vertex(i)
                self.__vertexList.append(v)

        if type(args[0]) == type([]) and len(args[0]) > 0 and type(args[0][0]) == type(0): ## Init apenas com lista de pesos
            self.__numberOfVertices = len(args[0])
            self.__adjList = [0]*self.__numberOfVertices
            for i in range(self.__numberOfVertices):
                self.__adjList[i] = []
            for i in range(self.__numberOfVertices):
                v = Vertex(i)
                self.__vertexList.append(v)
                self.__vertexList[i].SetWeight(args[0][i])
        
        if type(args[0]) == type([]) and type(args[0][0]) == type([]): ## Init com matriz de adjacência
            self.__numberOfVertices = len(args[0])
            self.__adjList = [0]*self.__numberOfVertices
            for i in range(self.__numberOfVertices):
                self.__adjList[i] = []
            for u in range(self.__numberOfVertices):
                vertexU = Vertex(u)
                self.__vertexList.append(vertexU)
                for v in range(self.__numberOfVertices):
                    if args[0][u][v] == 1:
                        edgeName = f"{(u,v)}"
                        try:
                            if type(args[1][1]) == type([]):
                                uv = OrientedEdge(edgeName, u, v, args[1][u][v])
                            if type(args[1][1]) == type(0):
                                uv = OrientedEdge(edgeName, u, v)
                                self.__vertexList[u].SetWeight(args[1][u])
                        except:
                            uv = OrientedEdge(edgeName, u, v)
                        self.__adjList[u].append(uv)
                if len(args) > 2:
                    self.__vertexList[i].SetWeight(args[2][i])


    
    def PrintVertices(self):
        if self.__numberOfVertices > 0:
            print("Lista de Vértices: (", end='')
            for i in range(self.__numberOfVertices-1):
                print(self.__vertexList[i], end=', ')
            print(self.__vertexList[self.__numberOfVertices-1], end=')\n')
        else:
            print("Grafo sem vértices")

    def PrintEdges(self):
        if self.__numberOfVertices > 0:
            for u in range(self.__numberOfVertices):
                print(f"{u} - ", end='')
                if len(self.__adjList[u]) == 0:
                    print('')
                else:
                    for v in range(len(self.__adjList[u])-1):
                        print(self.__adjList[u][v].GetEdgeName(), end=', ')
                    print(self.__adjList[u][len(self.__adjList[u])-1].GetEdgeName())

        else:
            print("Grafo sem vértices")
