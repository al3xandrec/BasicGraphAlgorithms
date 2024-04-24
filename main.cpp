// Run the Prim Algorithm through an input matrix

#include <iostream>
#include <iomanip>
#include <string> 

#include "libs/Graphs.h"
#include "libs/MST.h"

#define INF 10000000

using namespace std;

const char separator    = ' ';
const int numWidth      = 15;
template<typename T> void printElement(T t) {
    cout << right << setw(numWidth) << setfill(separator) << t;
}

// Graph
const int N = 5;

//               0  1  2  3  4
int M[N][N] = { {0, 1, 2, 9, 0},   // 0 
                {1, 0, 5, 0, 7},   // 1
                {2, 5, 0, 4, 6},   // 2
                {9, 0, 4, 0, 8},   // 3
                {0, 7, 6, 8, 0} }; // 4


int main() {
    
    SimpleGraph graphG;
    graphG.InitGraph(N);
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		graphG.AddEdge(i,j, M[i][j]);
    	}
    }
    
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) {
    		cout << graphG.GetEdgeWeight(i,j) << " ";
    	}
    	cout << endl;
    }
	int Pi[N];
	MSTPrim(graphG, 0, Pi);
    
    printElement("Elemento");
    printElement("Predecessor");
    cout << endl;
    
    for (int k = 0; k < N; k++) {
        printElement(k);
        printElement(Pi[k]);
        cout << endl;
    }

    return 0;
}
