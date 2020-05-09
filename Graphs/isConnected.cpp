#include <iostream>
using namespace std;
#include <queue>

// DFS(Depth first traversal)
// sv is starting vertex
void printDFS(int **edges, int n, int sv, bool *visited) {
	// cout <<	sv << " ";
	visited[sv] = true;

	// Recursive call on connected vertices
	for(int i=0; i < n; i++) {
		if(i == sv) {
			continue;
		}

		if(edges[sv][i] == 1) {
			if(visited[i]) { // Skip if already visited
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

bool isPathDFS(int** edges, int n) {
	// Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }
	
	// Now use printDFS as helper function and pass visited there
    // Run DFS once with any vertex as sv
    printDFS(edges, n, 0, visited);
	// If we find any non-visited vertex after running DFS once, it means graph is disconnected
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			return false;
		}
	}
	// Cleanup
	delete [] visited;
    
    return true;
}


// Main
// Sample input
/*
4 4
0 1
0 3
1 2
2 3

#output
true


== Disconnected graph case
4 3
0 1
1 3 
0 3

#output
false

*/
int main() {
	int n;
	int e;
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

	// DFS	
	// cout<<"isPathDFS(): ";
	bool output = isPathDFS(edges, n);
    if(output) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
	// cout<<endl;

	// Delete all the dynamically allocated memory
	//delete[] visited;
	for(int i = 0; i<n; i++) {
		// Delete sub-arrays
        delete edges[i];
    }
	// Free the 2d array itself
	delete[] edges;
}
