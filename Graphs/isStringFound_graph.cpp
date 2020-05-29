#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

// Find the cordinates for starting letter 'C'
pair<int, int> findC(char Graph[][MAXN],int N, int M, bool **visited) {
    // function findC()
    int iC = -1;
    int jC = -1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            // cout<<Graph[i][j]<<endl;
            if(Graph[i][j] == 'C' && !visited[i][j]) {
                iC = i;
                jC = j;
                break;
            }
        }
    	if(iC != -1 && jC != -1) {
            // Mark this 'C' as visited
            visited[iC][jC] = true;
            break;
        }
    }
    // print cordinates of C
    // cout<<iC<<" "<<jC<<endl; 
    
    pair<int, int> cij;
    cij.first = iC;
    cij.second = jC;
    
//     cout<<"pair values: ";
//     cout<<cij.first<<" "<<cij.second<<endl;
    
    return cij;
}

bool checkPath(pair<int, int> cur_ij, char Graph[][MAXN],int N, int M, bool **visited, string target) {
    // Base case
    if(target.length() == 0) {
        return true;
    }
    int iC = cur_ij.first;
    int jC = cur_ij.second;
    
    // checkAdjacent
	/* We will check from 0 to 7 positions around 'C' for nextLetter
    	0 1 2
        7 C 3
        6 5 4
    */
    
    // positions to add to check for adjacent values
    int move_i[] = {-1, -1, -1, 0, 1, 1,  1,  0};
    int move_j[] = {-1,  0,  1, 1, 1, 0, -1, -1};
    
    for(int i=0; i<8; i++) {
        int iPos = iC + move_i[i];
        int jPos = jC + move_j[i];

        if((iPos >=0 && iPos < N) && (jPos >=0 && jPos < M)) {
            // cout<<iPos<<" "<<jPos<<endl;
            pair<int, int> next_ij;
            next_ij.first = iPos;
            next_ij.second = jPos;
            char nextLetter = target[0];
            if(Graph[iPos][jPos] == nextLetter && !visited[iPos][jPos]) {
                // cout<<"nextLetter: "<<nextLetter<<" is adjacent!"<<endl;
                
                // Recursive call
                visited[iPos][jPos] = true;
                // cout<<iPos<<" "<<jPos<<endl;
                //return false;
                bool output = checkPath(next_ij, Graph, N, M, visited, target.substr(1));

                if(output == true) {
                    return true;
                } else {
                    // NOTE: When going back just mark the nodes as unvisited, if path is not found
                    visited[iPos][jPos] = false;
                }
            }
        }
    }
    
    // If in all adjacent cells the next Letter is not found 
    return false;
}

int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    //print
    // for(int i=0; i<N; i++) {
    //     cout<<Graph[i];
    //     cout<<endl;
    // }
    // Create 2D matrix(2D array) for visited 
    bool** visited = new bool*[N];
    for(int i = 0; i<N; i++) {
        visited[i] = new bool[M];
        // Initialize to avoid garbage values
        for(int j = 0; j<M; j++) {
            visited[i][j] = false;
        }
    }
    
    // Find first 'C'
    pair<int, int> cij = findC(Graph, N, M, visited);
    // cout<<"Returned pair values: ";
    // cout<<cij.first<<" "<<cij.second<<endl;


    //function checkPath()
    string cn = "CODINGNINJA";
    // First call after 'C'
    while(cij.first != -1 && cij.first != -1 ) {// Run loop till you find full word, or search for next 'C'
        // NOTE: Do not erase mark on visited 'C'
        bool output = checkPath(cij, Graph, N, M, visited, cn.substr(1));
        if(output) {
            return true;
        } else {
            // Find next C in unvisited nodes
            cij = findC(Graph, N, M, visited);
            // cout<<"Inside while Returned pair values: ";
            // cout<<cij.first<<" "<<cij.second<<endl;
        }
    }
    // cout<<cn.length()<<endl;
    // for(int i=1; i<cn.length(); i++) {
    //     // cout<<cn[i]<<" ";
    //     char nextLetter = cn[i];
    //     // cout<<nextLetter<<endl;
    //     checkPath(cij, Graph, N, M, nextLetter);
    // }
    cout<<endl;
    // for(int i=0; i<)
    // checkPath()
    
    // cout<<"Not Found"<<endl;
    return false;
}

int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}
