#include <iostream>
using namespace std;
#include <cmath>

// // Method #1
// // Brute force recursive solution - O(2^n) approx. exponential
// // This does not pass timelimt in test cases
// long long int balancedBTs(int h) {
// 	// Base case
//     if( h == 0 || h == 1) {
//         return 1;
//     }
    
//     // When we solve it, we get soltion like a * (a + 2b) 
//     /* h-1 , h-1
//     *  h-2 , h-1,
//     *  h-1 , h-2
//     */
//     // As given in question
//     // This number can be huge, so return output modulus 10^9 + 7.
//     long long m = pow(10, 9) + 7;
//     return balancedBTs(h-1) % m * balancedBTs(h-1) % m + \
//            balancedBTs(h-2) % m * balancedBTs(h-1) % m + \
//            balancedBTs(h-1) % m * balancedBTs(h-2) % m;
// }

// Method #2
// recursive solution with memoization - O(n) approx. due to memoization
// This does not pass timelimt in test cases
long long int balancedBTs(int h, long long int *ans) {
	// Base case
    if( h == 0 || h == 1) {
        ans[h] = 1;
        return ans[h];
    }
    
    // Memoization
    if(ans[h] != -1) {
        return ans[h];
    }
    // When we solve it, we get soltion like a * (a + 2b) 
    /* h-1 , h-1
    *  h-2 , h-1,
    *  h-1 , h-2
    */
    // As given in question
    // This number can be huge, so return output modulus 10^9 + 7.
    long long m = pow(10, 9) + 7;
    long long int result = \
           balancedBTs(h-1, ans) % m * balancedBTs(h-1, ans) % m + \
           balancedBTs(h-2, ans) % m * balancedBTs(h-1, ans) % m + \
           balancedBTs(h-1, ans) % m * balancedBTs(h-2, ans) % m;
    // Save result
    ans[h] = result % m;
    return ans[h];
}

long long int balancedBTs(int h) {
    // Create ans array of size n+1 (0, 1, .... , n)
    long long int *ans = new long long int[h+1];
    // Initialize with -1
    for(int i = 0; i < h+1; i++) {
        ans[i] = -1;
    }
    long long int result = balancedBTs(h, ans);
    // Debug
//     for(int i = 0; i < h+1; i++) {
//         cout<<i << "\t" << ans[i]<<endl;
//     }
    
    return result;
}

// Method #3
// DP solution, O(n)
long long int binaryTreesOfHeightH(int h) {
    long long int *ans = new long long int[h+1];
    
    ans[0] = 1;
    ans[1] = 1;
    
    // As given in question
    // This number can be huge, so return output modulus 10^9 + 7.
    long long m = pow(10, 9) + 7;
    for(int i = 2; i<=h ; i++) {
        long long int result = ans[i-1] %m * ans[i-1] %m + \
            	 ans[i-2] %m * ans[i-1] %m + \
            	 ans[i-1] %m * ans[i-2] %m;
        ans[i] = result %m;
    }
    
    return ans[h];
}

// Main
int main() {
    int h;
	cout<<"Enter the hegiht of BT: ";
    cin >> h;
    // Memoization solution method2 call 
	//int ans = balancedBTs(h);
    // DP solution method3 call  
    int ans = balancedBTs(h);
    cout << ans << endl;
}

