#include <iostream>
using namespace std;
#include <queue>

// BFS(Breadth first traversal)
// sv is starting vertex
bool hasPahtBFS(int **edges, int n, int sv, int ev, bool *visited) {
    // If sv and ev is same, return true
    if(sv == ev) {
        // cout<<"DEBUG: sv and ev is same"<<endl;
        // cout<<true<<endl;
        return true;
    }
    
	// Make queue for pending nodes
	queue<int> pendingVertices;
	// Push sv to q and mark visited
    pendingVertices.push(sv);
    visited[sv] = true;
    
    
    while(pendingVertices.size() != 0) {
        int front = pendingVertices.front();
        pendingVertices.pop();
        // Check if ev is not directly connected to current vertex
        if(edges[front][ev] == 1) {
            return true;
        }
        // Otherwise call on furhter vertices
        for(int i=0; i < n; i++) {
            if(i == front) {
                continue;
            }

            if(edges[front][i] == 1 && !visited[i]) {
                // cout<<"DEBUG: "<<front<<" pushing -> "<<i<<endl;
                // Push and mark visited
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    // If no path found 
    return false;
}

bool hasPath(int **edges, int n, int sv, int ev) {
    // Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }

    bool output = hasPahtBFS(edges, n, sv, ev, visited);
    // cout<<"DEBUG: output from hasPathBFS(): "<<output<<endl;
    // Cleanup and return
    delete[] visited;
    return output;
}

int main() {
    int n, e;
    cin >> n >> e;
	// Create adjacency matrix(2D array)
	int** edges = new int*[n];
	for(int i = 0; i<n; i++) {
		edges[i] = new int[n];
		// Initialize to avoid garbage values
		for(int j = 0; j<n; j++) {
			edges[i][j] = 0;
		}
	}

	// Fill the adjacency matrix
	for(int i=0; i<e; i++) {
		int f, s; // Vertices - first, second
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
    
    // Input sv and ev for search
    int sv, ev;
    cin >> sv >> ev;
    
    // cout<<"DEBUG:"<<sv<<" "<<ev<<endl;
    bool output = hasPath(edges, n, sv, ev);
    // cout<<"DEBUG: output from hasPath()): "<<output<<endl;
	if(output == true) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    
    
    // Delete all the dynamically allocated memory
	for(int i = 0; i<n; i++) {
		// Delete sub-arrays
        delete edges[i];
    }
	// Free the 2d array itself
	delete[] edges;
    
    return 0;
}
