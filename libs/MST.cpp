#include "libs/Graphs.h"

#ifndef INF
#define INF 10000000

// PRIM's Algorithm



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


void MSTPrim(SimpleGraph graphG, int rootVertex) {
	int N = graphG.GetNumberOfVertices();
	
	bool Q[N];
	int Pi[N];
	int key[N];
	
    for (int k = 0; k < N; k++) {
        key[k] = INF;
        Pi[k] = -1;
    }
    
    key[r] = 0;
    for (int k = 0; k < N; k++) {
        Q[k] = true;
    }
    
    while (CheckQueue(N, Q)) {
        int u = ExtractMin(N, Q, key);
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

#endif
