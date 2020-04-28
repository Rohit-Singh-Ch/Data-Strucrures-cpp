#include <iostream>
using namespace std;
/* This is classic case of fibonnaci, when you can jump 1 step and 2 step,
 * question has been modified by including that child can jump 3 steps also.
 * f(n) = f(n-1) + f(n-2) + f(n-3)
 */

// Method 1 - Recursion with memoization (O(n))
// long staircase(int n, int *ans){
// 	// Base case
//     if(n < 1) {
//         return 1;
//     }
    
//     if(n == 1) {
//         return 1;
//     }
//     if(n == 2) {
//         return 2;
//     }
    
//     if(n == 3) {
//         return 4;
//     }
    
//     // Recursive calls
//     long res1 = 0 , res2 = 0, res3 = 0;
// 	if(n > 1) { res1 = staircase(n-1, ans); }
//     if(n > 2) { res2 = staircase(n-2, ans); }
//     if(n > 3) { res3 = staircase(n-3, ans); }
    
//     long res = res1 + res2 + res3;
//     // Save ans
//     ans[n] = res;
//     return ans[n];
// }

// long staircase(int n) {
// 	long *ans = new long[n+1];
//     // Initialize
//     for(int i = 0; i <= n; i++) {
//         ans[i] = -1;
//     }
    
//     return staircase(n, ans);   
// }

// Itrative solution , Bottom-Up , with ans saving (i.e. DP)
// O(n)
long staircase(int n) {
    // Input check
    if(n == 0 || n == 1) { // Otherwise we get error during allocation of 
        return 1;
    } 
    
    if(n == 2) {
        return 2;
    }
    
    if(n == 3) {
        return 4;
    }
    
    // Below Code runs if n > 3
	long *ans = new long[n+1];
    // Initialize
    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }
    
    // Note: If n is < 3 you can get outOfIndex error, so be careful
    // Assign the Base conditions
	ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    
    for(int i = 4; i <=n; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    
    return ans[n];
}

// Main
int main() {
	int n; 
  	cin >> n ;
  	cout << staircase(n) << endl;
}
