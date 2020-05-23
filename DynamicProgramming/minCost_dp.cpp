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
 
	// If si or sj is outOfBound then return with INT_MAX 
	if(si >= m || sj >= n) {
		return INT_MAX;
	} 
    
	// recursive calls
    // Directions (i+1, j), (i, j+1) and (i+1, j+1).
    
	int res1 = helper_minCostPath(input, m, n, si+1, sj);
    int res2 = helper_minCostPath(input, m, n, si, sj+1);
    int res3 = helper_minCostPath(input, m, n, si+1, sj+1);
    
    // Find minimum cost, add value of current cell to min result and return
    return min(res1, min(res2, res3)) + input[si][sj];
}

int minCostPath(int **input, int m, int n) {
    // // Testing base case
    // return helper_minCostPath(input, m, n, m-1, n-1);
    // Start from (0, 0)
    return helper_minCostPath(input, m, n, 0, 0);
}


// Method2 - Memoization solution 
//Time Complexity O(N), N -> m*n total no. of input values
//Space Complexity O(N), N -> m*n for output matrix
int helper_minCostPath_Mem(int **input, int m, int n, int si, int sj, int **output) {
    // Base case
    if((si == m-1) && (sj == n-1)) {
        // Reached (m-1, n-1)
		// Save answer
		output[si][sj] = input[m-1][n-1];
        return output[si][sj];
    }

    // If si or sj is outOfBound then return with INT_MAX 
    if(si >= m || sj >= n) {
        return INT_MAX;
    }

	// Check if answer is already calculated
    if(output[si][sj] != -1) {
		return output[si][sj];
	} 
	// recursive calls
    // Directions (i+1, j), (i, j+1) and (i+1, j+1).

    int res1 = helper_minCostPath_Mem(input, m, n, si+1, sj, output);
    int res2 = helper_minCostPath_Mem(input, m, n, si, sj+1, output);
    int res3 = helper_minCostPath_Mem(input, m, n, si+1, sj+1, output);

    // Find minimum cost, add value of current cell to min result and return
	// Save answer for future use
	int ans = min(res1, min(res2, res3)) + input[si][sj];
	output[si][sj] = ans;
    return output[si][sj];
}

int minCostPath_Mem(int **input, int m, int n) {
	// Create 2D output array for memoization	
	int **output = new int*[m];
	for(int i=0; i<m; i++) {
		output[i] = new int[n];
	}

	// Initiazlization of memoization output array
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			output[i][j] = -1;
		}
	}
	
    // Start from (0, 0)
    return helper_minCostPath_Mem(input, m, n, 0, 0, output);
}


// Method3: DP - Bottom Up, Complexity O(N), N -> m*n total no. of input values
//Time Complexity O(N), N -> m*n total no. of input values
//Space Complexity O(N), N -> m*n for output matrix
int minCostPath_dp(int **input, int m, int n) {
	// Create 2D output array for memoization   
    int **output = new int*[m];
    for(int i=0; i<m; i++) {
        output[i] = new int[n];
    }

	// Fill the last cell i.e. destination
	output[m-1][n-1] = input[m-1][n-1];

	// Fill last row(right to left)
	for(int j=n-2; j>=0; j--) {
		output[m-1][j] = output[m-1][j+1] + input[m-1][j];
	}

	// Fill last column(bottom to top)
    for(int i=m-2; i>=0; i--) {
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }

	// Fill remaining cells
    for(int i=m-2; i>=0; i--) {
    	for(int j=n-2; j>=0; j--) {
			int min_res = min(output[i+1][j+1], min(output[i][j+1],output[i+1][j]));
			output[i][j] = input[i][j] + min_res;
		}
	}	
	
	return output[0][0];
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
	// Brute force recursive solution
	cout<<"\nminCostPath_recursion: ";
    cout << minCostPath(arr, n, m) << endl;
	// Solution with memoization 
	cout<<"\nminCostPath_memoization: ";
    cout << minCostPath_Mem(arr, n, m) << endl;
	// DP solution(Iterative)
	cout<<"\nminCostPath_dp: ";
	cout << minCostPath_dp(arr, n, m) << endl;

	return 0;
}
