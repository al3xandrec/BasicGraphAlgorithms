
#ifndef XAN_GRAPHS_H
#include "Graphs.h"
#endif

#define XAN_MST_H

#ifndef INF
#define INF 10000000

// Prim's Algorithm

bool CheckQueue(int N, bool *Q) {
    for (int k = 0; k < N; k++) {
        if (Q[k] == true) return true;
    }
    return false;
}

int ExtractMin(int N, bool *Q, int *key) {
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


void MSTPrim(SimpleGraph graphG, int rootVertex, int *Pi) {
	int N = graphG.GetNumberOfVertices();
	bool Q[N];
	int key[N];
	
    for (int k = 0; k < N; k++) {
        key[k] = INF;
        Pi[k] = -1;
    }
    
    key[rootVertex] = 0;
    for (int k = 0; k < N; k++) {
        Q[k] = true;
    }
    
    while (CheckQueue(N, Q)) {
        int u = ExtractMin(N, Q, key);
        for (int v = 0; v < N; v++) {
            if (graphG.GetEdgeWeight(u,v) != 0) {
                if (Q[v] == true && graphG.GetEdgeWeight(u,v)  < key[v]) {
                    Pi[v] = u;
                    key[v] = graphG.GetEdgeWeight(u,v) ;
                }
            }
        }
    }
}






// Kruskal's Algorithm



#endif
