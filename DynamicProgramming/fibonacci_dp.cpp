#include <iostream>
using namespace std;

// Iterative solution with DP
// Complexity -> O(n)
int fibo_3(int n) {
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;

	for(int i = 2; i<=n ; i++) {
		ans[i] = ans[i-1] + ans[i-2];
	}

	return ans[n];
}


// Recursive solution
// O(2^n) -- > very bad complexity, exponential
int fibo(int n) {
	if(n <= 1) {
		return n;
	}
	
	int a = fibo(n-1);
	int b = fibo(n-2);

	return a + b;
}

// Recurvise Solution
// Complexity -> O(n), previously it used to 2^n due to blind repeated calls in recursion
int fibo_helper(int n, int *ans) {
	if(n <= 1) {
        return n;
    }

	// Step1: Check if output already exists
	if(ans[n] != -1) {
		return ans[n];
	}

	// Step2: If not already calculated, then calculate
	int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

	// Step3: Save the value for future use
	ans[n] = a+b;

    return ans[n];
}

int fibo_2(int n) {
	// Array to store already calculated values
	// 0, 1, ... n ,, Total n+1 values	
	int *ans = new int[n+1];
	// Initialize
	for(int i = 0; i <= n; i++) {
		ans[i] = -1;
	}

	return fibo_helper(n, ans);
}
// Main
int main() {
	int n;
	cin >> n;
	//cout << fibo(n) << endl;
	cout << fibo_3(n) << endl;
}
