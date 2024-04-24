// Graph Class Designed by XANADE

#define XAN_GRAPHS_H

class SimpleGraph {
	private:
		int numberOfVertices, numberOfEdges; // order and size
		float *weigthFunction; // weight
		
	public:
		void InitGraph(int order) {
			numberOfVertices = order;
			weigthFunction = (float*)calloc(numberOfVertices*numberOfVertices, sizeof(float));
			numberOfEdges = 0;
		}
		
		int GetNumberOfVertices() {
			return numberOfVertices;
		}
		
		int GetNumberOfEdges() {
			return numberOfEdges;
		}
		
		void AddEdge(int i, int j, float w) {
			weigthFunction[i + numberOfVertices*j] = w;
			numberOfEdges++;
		}
		
		float GetEdgeWeight(int i, int j) {
			return weigthFunction[i + numberOfVertices*j];
		}
};

