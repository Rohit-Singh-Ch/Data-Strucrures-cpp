#include <iostream>
using namespace std;
#include <queue>

// DFS(Depth first traversal)
// sv is starting vertex
void printDFS(int **edges, int n, int sv, bool *visited) {
	cout <<	sv << " ";
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

// BFS(Breadth first traversal)
// sv is starting vertex
void printBFS(int **edges, int n, int sv, bool *visited) {
	// Make queue for pending nodes
	queue<int> pendingVertices;
	// Push sv to q and mark visited
    pendingVertices.push(sv);
    visited[sv] = true;
    
    while(pendingVertices.size() != 0) {
        int front = pendingVertices.front();
        pendingVertices.pop();
        // Print
        cout <<	front << " ";
        
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
}

void BFS(int** edges, int n) {
	// Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }

    // Now use printDFS as helper function and pass visited there
    // We need to check for not-visited vertices, in case of disconnected graph
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            printBFS(edges, n, i, visited);
        }
    }
    // Cleanup
    delete [] visited;
	
}

void DFS(int** edges, int n) {
	// Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }
	
	// Now use printDFS as helper function and pass visited there
	// We need to check for not-visited vertices, in case of disconnected graph
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			printDFS(edges, n, i, visited);
		}
	}
	// Cleanup
	delete [] visited;
}


// Main
// Sample input
/*
4 3
0 2
0 3
2 1

#output
DFS print: 0 2 1 3
BFS print: 0 2 3 1 


== Disconnected graph case
7 5
0 2
0 3
2 3
1 4
5 6

#output(Main thing is that it is working for disconnected also)
DFS print: 0 2 3 1 4 5 6
BFS print: 0 2 3 1 4 5 6
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

	// Maintain array for visited nodes
	/*
	bool* visited = new bool[n];
	for(int i = 0; i<n ; i++) {
		visited[i] = false;
	}
	*/
	// DFS	
	cout<<"DFS print: ";
	DFS(edges, n);
	cout<<endl;
	
	// BFS	
	cout<<"BFS print: ";
	BFS(edges, n);
	cout<<endl;
	// Delete all the dynamically allocated memory
	//delete[] visited;
	for(int i = 0; i<n; i++) {
		// Delete sub-arrays
        delete edges[i];
    }
	// Free the 2d array itself
	delete[] edges;
}
