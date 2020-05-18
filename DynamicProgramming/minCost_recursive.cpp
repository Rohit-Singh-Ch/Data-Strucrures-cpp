#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Method1 - Recursive solution , Complexity exponential approx. O(n3)
int helper_minCostPath(int **input, int m, int n, int si, int sj) {
    // Base case
    if((si == m-1) && (sj == n-1)) {
        // Reached (m-1, n-1)
        return input[m-1][n-1];
    }
    
    // Initialization
    int res1 = INT_MAX;
    int res2 = INT_MAX;
    int res3 = INT_MAX;
    int res  = INT_MAX;
    // recursive call
    // Directions (i+1, j), (i, j+1) and (i+1, j+1).
    // Direacion1 - (i+1, j))
    if(si+1 < m) { 
        res1 = helper_minCostPath(input, m, n, si+1, sj);
    }
    
    // Direacion2 - (i, j+1))
    if(sj+1 < n) { // Check for valid limits
        res2 = helper_minCostPath(input, m, n, si, sj+1);
    }
    
    // Direacion3 - (i+1, j+1)
    if(si+1 < m && sj+1 < n) {
        res3 = helper_minCostPath(input, m, n, si+1, sj+1);
    }
    
    // Find minimum cost
    res = min(res1, min(res2, res3));
    
    // Add value of current cell to answer and return
    return input[si][sj] + res;
}

int minCostPath(int **input, int m, int n) {
    // // Testing base case
    // return helper_minCostPath(input, m, n, m-1, n-1);
    // Start from (0, 0)
    return helper_minCostPath(input, m, n, 0, 0);
}

// Main
/*
3 4
3 4 1 2
2 1 8 9
4 7 8 1

13
*/
int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
