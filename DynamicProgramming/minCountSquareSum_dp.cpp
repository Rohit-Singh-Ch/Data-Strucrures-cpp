#include<iostream>
using namespace std;

// // Mehtod - 1
// // Naive solution - O(n2) or more , very bad
// // Recursion
// int minCount(int n){
//     // Base case
//     if(n <= 1) {
//         return n;
//     }
    
//     int minResult = n;
//     // Run loop from 1, 2, 3 --- , sq.root(n)
//     for(int i = 1; (i*i) <= n; i++) {
//         int res = minCount(n - (i*i)) + 1;
//         if(res < minResult) {
//             minResult = res;
//         }
//     }
    
//     return minResult;
// }

// // Mehtod - 2
// // Memoization - O(n) 
// int minCount(int n, int *ans) {
//     // Base case
//     if(n <= 1) {
//         return n;
//     }
    
//     // Check if ans already filled
//     if(ans[n] != -1) {
//         return ans[n];
//     }
    
//     int minResult = n;
//     // Run loop from 1, 2, 3 --- , sq.root(n)
//     for(int i = 1; (i*i) <= n; i++) {
//         int res = minCount(n - (i*i), ans) + 1;
//         if(res < minResult) {
//             minResult = res;
//         }
//     }
    
//     // Save ans
//     ans[n] = minResult;
//     return ans[n];
// }

// int minCount(int n) {
//     int *ans = new int[n+1];
//     // Initialization
//     for(int i = 0; i<=n; i++) {
//         ans[i] = -1;
//     }
//     return minCount(n, ans);
// }

// Mehtod - 3
// Iterative with memoization(Bottom - Up approach) -- DP - O(n) 
int minCount(int n) {
	// count[i] - represents minimum count of squares for int n
	if(n <= 3) {
		return n;
	}

	int count[n+1];
	count[0] = 0;
	count[1] = 1;
	count[2] = 2;
	count[3] = 3;

	for(int i = 4; i <= n ; i++) {
		int ans = i;
		for(int j = 1; j <= i/2; j++) {
			int k = i - (j * j);
			if(k >= 0) {
				ans = min(ans, count[k] + 1);
			}
			count[i] = ans;
		}
	}

	return count[n];
}

// Main
int main(){
    
    int num;
	cout<<"Enter n: ";
    cin >> num;
    cout << minCount(num)<<endl;
    
}


