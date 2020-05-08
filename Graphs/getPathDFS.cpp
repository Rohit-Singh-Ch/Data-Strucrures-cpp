#include <iostream>
#include <vector>
using namespace std;

// DFS(Depth first traversal)
// sv is starting vertex
void helper_getPathDFS(int **edges, int n, int sv, int ev, bool *visited, vector<int> *output) {
	cout<<"Recursive call with sv: "<<sv<<endl;
	// Mark sv as visted
	visited[sv] = true;
	if(sv == ev) {
		//cout<<"Going to push sv: "<<sv<<endl;
    	output -> push_back(sv);
		//cout<<"Successfully returning"<<endl;
		return;
    }


	// Recursive call on connected vertices
	for(int i=0; i < n; i++) {
		if(i == sv) {
			continue;
		}

		if(edges[sv][i] == 1) {
			if(visited[i]) { // Skip if already visited
				continue;
			}
			visited[i] = true;
			helper_getPathDFS(edges, n, i, ev, visited, output);
			// We get non-empty output, it means path is found
    		//cout<<"output -> size: "<<output -> size()<<endl;
			
			if(!output -> empty()) {
				//cout<<"Going to push sv: "<<sv<<endl;
    			output -> push_back(sv);
				//cout<<"Successfully returning"<<endl;
				return;
			}
		}
	}
}

void getPathDFS(int** edges, int n, int sv, int ev) {
    // Maintain array for visited nodes
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }
	
	vector<int> *output = new vector<int>();
	helper_getPathDFS(edges, n, sv, ev, visited, output);
	cout<<"DEBUG:: output vector: "<<endl;
    cout<<"output -> size: "<<output -> size()<<endl;
    vector<int> :: iterator i = output -> begin();
    while(i != output -> end()) {
        cout << *i << " "; 
        i++;
    }
	cout<<endl;

//	for(int i=0; i<output -> size(); i++) {
//		cout<<"i: "<<i<<endl;
//		output -> at(i);
//	}
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
	cout<<"DEBUG:: v1: "<<tempX<<" v2: "<<tempY<<endl;

	// getPath DFS
	getPathDFS(edges, n, tempX, tempY);
    return 0;
}
