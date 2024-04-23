// Run the Prim Algorithm through an input matrix

#include <iostream>
#include <iomanip>
#include <string> 

#include "libs/Graphs.h"

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

// Lists
bool Q[N];
int Pi[N];
int key[N];

bool CheckQueue(void) {
    for (int k = 0; k < N; k++) {
        if (Q[k] == true) return true;
    }
    return false;
}

int ExtractMin(void) {
    int kmin, keyMin;
    keyMin = INF;
    for (int k = 0; k < N; k++) {
        if (Q[k] == true) {
            if (key[k] < keyMin) {
                kmin = k;
                keyMin = key[k];
            }
        }
    }
    
    Q[kmin] = false;
    return kmin;
}

void MSTPrim(int r) {
    for (int k = 0; k < N; k++) {
        key[k] = INF;
        Pi[k] = -1;
    }
    
    key[r] = 0;
    for (int k = 0; k < N; k++) {
        Q[k] = true;
    }
    
    while (CheckQueue()) {
        int u = ExtractMin();
        for (int v = 0; v < N; v++) {
            if (M[u][v] != 0) {
                if (Q[v] == true && M[u][v] < key[v]) {
                    Pi[v] = u;
                    key[v] = M[u][v];
                }
            }
        }
    }
}


int main() {
    MSTPrim(0);
    
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
    
    printElement("Elemento");
    printElement("Predecessor");
    cout << endl;
    
    for (int k = 0; k < N; k++) {
        printElement(k);
        printElement(Pi[k]);
        cout << endl;
        //cout << k << " -- " << Pi[k] << endl;
    }

    return 0;
}
