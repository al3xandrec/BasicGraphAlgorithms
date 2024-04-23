// Graph Class Designed by XANADE

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
		
		void AddEdge(int i, int j, float w) {
			weigthFunction[i + numberOfVertices*j] = w;
			numberOfEdges++;
		}
		
		float GetEdgeWeight(int i, int j) {
			return weigthFunction[i + numberOfVertices*j];
		}
};

