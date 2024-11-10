// C++ Graph Class Designed by XANADE

#ifndef XAN_GRAPHS_H
#define XAN_GRAPHS_H

#include <set>

// Declarations

class Vertex;
class Edge;
class Simplegraph;


// Implementations

class Vertex {
	private:
		int vertexName;
		Edge *incidenceList;
	
	public:
		Vertex(int name) {
			this->vertexName = name;
			this->incidenceList = NULL;
		}
		~Vertex() {
			free(this->incidenceList);
		}

		int GetVertexName() {
			return this->vertexName;
		}

		bool operator==(Vertex v) {
			if (vertexName == v.GetVertexName())
				return true;
			else
				return false;
		}

		void AddEdge(Edge edge) {
			if (edge.GetHead() == *this) {
				int numberOfEdges = length(incidenceList);
			}
		}
};

class Edge {
	private:
		int edgeName;
		Vertex head, tail;
		float edgeWeight;

	public:
		void SetEdge(Vertex h, Vertex t, float w) {
				this->head = h;
				this->tail = t;
				edgeWeight = w;
		}
		Vertex GetEdgeEndpoints(int ht) { // 1 for head, 2 for tails
			if (ht == 1) return head;
			if (ht == 2) return tail;
		}
		
		void SetEdgeWeight(float w) {
			edgeWeight = w;
		}
		
		float GetEdgeWeight(void) {
			return edgeWeight;
		}

		Vertex GetHead() {

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











#endif