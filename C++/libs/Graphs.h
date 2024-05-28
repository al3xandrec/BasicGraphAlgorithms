// Graph Class Designed by XANADE

#define XAN_GRAPHS_H

class Edge {
	private:
		int head, tail;
		float edgeWeight;
	public:
		void SetEdge(int h, int t, float w) {
				head = h;
				tail = t;
				edgeWeight = w;
		}
		int GetEdgeEndpoints(int ht) { // 1 for head, 2 for tails
			if (ht == 1) return head;
			if (ht == 2) return tail;
		}
		
		void SetEdgeWeight(float w) {
			edgeWeight = w;
		}
		
		float GetEdgeWeight(void) {
			return weight;
		}
};

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

