#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
/*
NOTE:
In file included from /usr/include/c++/5/unordered_map:35:0,
                 from getPathBFS.cpp:4:
/usr/include/c++/5/bits/c++0x_warning.h:32:2: error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support must be enabled with the -std=c++11 or -std=gnu++11 compiler options.
 #error This file requires compiler and library support \

Solution:
g++ -std=gnu++11 getPathBFS.cpp
*/

using namespace std;

// DFS(Depth first traversal)
// sv is starting vertex
vector<int> helper_getPatBFS(int **edges, int n, int sv, int ev, bool *visited) {
    vector<int> output;

    // If sv and ev is same, return true
    if(sv == ev) {
        output.push_back(sv);
        return output;
    }
    
	// Make queue for pending nodes
	queue<int> pendingVertices;
	// Push sv to q and mark visited
    pendingVertices.push(sv);
    visited[sv] = true;
    
    // Maintain a hasmap to backtrack path
    unordered_map<int, int> tracker;
    
    while(pendingVertices.size() != 0) {
        int front = pendingVertices.front();
        pendingVertices.pop();
        // Check if ev is not directly connected to current vertex
        // if(edges[front][ev] == 1) {
        //     return true;
        // }
        // If Vertex FOUND
        if(front == ev) { 
            output.push_back(ev);
            // Check if vertex is found yet
            int curVertex = ev;
            while(true) {
                int prevVertex = tracker[curVertex]; 
                output.push_back(prevVertex);
                
                // Breaking condition
            	if(prevVertex == sv) {
                    break;
                }
                // Update
                curVertex = prevVertex;
            }
            return output;
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
                // Update hashmap, who pushed the next vertex
                tracker[i] = front;
            }
        }
    }
    // If no path found, output will be empty
    return output;

}

void getPathBFS(int** edges, int n, int sv, int ev) {
    // Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }

    vector<int> output;
    output = helper_getPatBFS(edges, n, sv, ev, visited);
    vector<int> :: iterator i = output.begin();
    while(i != output.end()) {
        cout << *i << " "; 
        i++;
    }
    cout<<endl;

    // Cleanup and return
    delete[] visited;
    return;
}

/* Input
4 4
0 1
0 3
1 2
2 3
1 3

output;
3 0 1
*/
int main()
{
    int n, e, tempX, tempY;
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
    
    // Input v1(from) and v2(to) vertices for path
	cin >> tempX >> tempY;
	// cout<<"DEBUG:: v1: "<<tempX<<" v2: "<<tempY<<endl;

	// getPath DFS
    getPathBFS(edges, n, tempX, tempY);
    return 0;
}
