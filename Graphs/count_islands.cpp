#include<iostream>
#include<vector>
using namespace std;

// DFS(Depth first traversal)
// sv is starting vertex
void printDFS(int **edges, int n, int sv, bool *visited) {
    // cout <<  sv << " ";
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

// Count connected groups in a graph
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    // Create adjacency matrix(2D array)
    int** edges = new int*[n];
    for(int i = 0; i<n; i++) {
        edges[i] = new int[n];
        // Initialize to avoid garbage values
        for(int j = 0; j<n; j++) {
            edges[i][j] = 0;
        }
    }

    // return -1;
    // Fill the adjacency matrix
    for(int i=0; i<m; i++) {
        int f, s; // Vertices - first, second
        // cin >> f >> s;
        // cout<<u.at(i)<<" ";
        // cout<<v.at(i)<<" ";
        // Our graph implementaion considers 0, 1, ... , n-1 vertex, question assumes 1 to N vertex numbers
        // So substract 1 to make input work with standard graph implentation
        f = u.at(i) - 1;
        s = v.at(i) - 1;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
	
    // return -1;
    // Maintain  the array for visited vertices
    bool* visited = new bool[n];
    for(int i = 0; i<n ; i++) {
        visited[i] = false;
    }
    
    // Run loop and count connected groups of islands
    int count = 0;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            count++;
            // Call DFS traversal
            // This will start traversal from sv and mark the connected vertices in process
            printDFS(edges, n, i, visited);
        }
    }
    
    // Cleanup
    delete [] visited;
    
    return count;
}

// Main
/*Input
3 3
1 2 3
1 2 3

output(all vetrex disconnected)
3

==
3 3
1 2 3
2 3 1

otuput 1 <-> 2 <-> 3 <-> 1
1
*/
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
