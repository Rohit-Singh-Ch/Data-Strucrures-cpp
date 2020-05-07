#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDeuplicates(int *a, int size) {
	vector<int> output;
	unordered_map<int, bool> seen;

	for(int i = 0; i < size; i++) {
		//cout<<"a["<<i<<"]"<<"\t"<<a[i]<<endl;
		if(seen.count(a[i]) > 0) {
			//cout<<"Here for --> a["<<i<<"]"<<"\t"<<a[i]<<endl;
			continue;
		}
		seen[a[i]] = true;
		output.push_back(a[i]);
	}

	return output;
}


// Main
int main() {
	int a[] = {1,2,3,3,2,1,4,3,6,5,5};
	vector<int> output = removeDeuplicates(a, 11);

	for(int i=0;i < output.size();i++) {
		cout<<output[i]<<endl;
	}
}
