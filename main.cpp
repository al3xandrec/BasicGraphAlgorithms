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






/*
#include <iostream>

using namespace std;

// Graph
const int N = 4;
int M[N][N];

// SETS
class Set {
    private:
    // 0 if not in same set; 1 otherwise;
    int setMatrix[N][N];
    
    public:
    // Init, 1 if i = j
    void InitSet(void) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) setMatrix[i][j] = 1;
                else setMatrix[i][j] = 0;
            }
        }
    }
    
    // check if i and j are in same component
    bool FindSet(int i, int j) {
        if (setMatrix[i][j] == 1) return true;
        return false;
    }
    
    void Union(int i, int j) {
        for (int i_a = 0; i_a < N; i_a++) {
            for (int j_a = 0; j_a < N; j_a++) {
                if (setMatrix[i][i_a] == 1 & setMatrix[j][j_a] == 1) {
                    setMatrix[i_a][j_a] = 1;
                    setMatrix[j_a][i_a] = 1;
                }
            }
        }
    }
    
    void GetSetMatrix(void) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << setMatrix[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl;
    }
};



int main() {
    Set conj;
    
    conj.InitSet();
    conj.GetSetMatrix();
    
    conj.Union(0, 1);
    conj.GetSetMatrix();
    
    conj.Union(2, 3);
    conj.GetSetMatrix();
    
    cout << conj.FindSet(0,1) << endl << endl;
    
    
    conj.Union(2, 1);
    conj.GetSetMatrix();

    return 0;
}

*/
