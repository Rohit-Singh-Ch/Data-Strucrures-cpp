#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int weight;
    
    // Constructor
    Edge() {
        source = -1;
        dest = -1;
        weight = -1;
    }
    
    // Setter
    void setValue(int ei, int ej, int wi) {
        source = ei;
        dest = ej;
        weight = wi;
    }
};

//findParent()
int findParent(int v, int *parent) {
    // Find parent recursively
	// Base case
	if(parent[v] == v) {
		return v;
	} 

	return findParent(parent[v], parent);
}



bool union_find(Edge curEdge, int *parent) {
    /* if parent of source and dest is same then
	// return false means it will introduce the cycle
	*/
    int sourceParent = findParent(curEdge.source, parent);
	int destParent = findParent(curEdge.dest, parent);

    bool is_safeToAdd = false;
    if(sourceParent != destParent) {
		// Update parent array
		// Make either of source or dest as parent
		parent[sourceParent] = destParent;
		is_safeToAdd = true;
    } else {
        // This will introduce cycle, so unsafe to add
        is_safeToAdd = false;
    }
    
	return is_safeToAdd;
}

// Compare two edges according to their weights.  
// Used in sort() for sorting an array of edges  
int myComp(const Edge a, const Edge b) {  
    return a.weight < b.weight;
} 

// Kruskal's Algorithm implementation
void kruskalMST(Edge *input, int V, int E) {
    // Sort input based on weight
    //sort(begin, end, compare function)
    sort(input, input+E, myComp);
    // Debug: Print input
    // for(int i=0; i<E; i++) {
    //     cout<<input[i].source<<" "<<input[i].dest<<" "<<input[i].weight<<endl;
    // }
    
    // Output MST
    Edge *output = new Edge[V-1];
    
    // Maintain parent array for union_find
    int *parent = new int[V];
    // Initialization
    for(int i=0; i<V; i++) {
		parent[i] = i;
    }

    // Count to keep track on no. of edges created in output MST
	int count = 0;
	int i = 0;
	while(count != V-1) {
		Edge curEdge = input[i];
		// Check if we can add the curEdge in MST or not
		bool is_safe = union_find(curEdge, parent);
        if(is_safe) {
            // Add egde to output MST
            output[count].setValue(curEdge.source,curEdge.dest,curEdge.weight);
            count++;
            //cout<<"count: "<<count<<endl;
		}
		
		//Update i
		i++;
	}
    
	// Print output
	cout<<"\n====Output==="<<endl;
    for(int i=0; i<V-1; i++) {
        // Output format is min(v1, v2), max(v1, v2) , weight
        int min_v = min(output[i].source, output[i].dest);
        int max_v = max(output[i].source, output[i].dest);
        cout<<min_v<<" "<<max_v<<" "<<output[i].weight<<endl;
    }

    // Clean up
    delete[] parent;
	delete[] output;
}

// Main
/*
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

====Output===
2 3 4
0 3 5
0 1 10
*/
int main()
{
    int V, E;
    cin >> V >> E;

	// Vertices: 0 - V-1
    // Edges E;
    Edge *input = new Edge[E];
    
    // Create edges
    for(int i=0; i<E; i++) {
        int ei, ej, wi;
        cin>>ei>>ej>>wi;
    	input[i].setValue(ei, ej, wi);
    }
    
    // Kruskal's MST 
    kruskalMST(input, V, E);

    
    // Clean up
    delete[] input;
    
    return 0;
}
