#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main() {
	unordered_map<string, int> umap;

	umap["a"] = 1;
	umap["b"] = 2;
	umap["c"] = 3;
	umap["d"] = 4;
	umap["d"] = 5;
	umap["e"] = 6;

	unordered_map<string, int> :: iterator it;
	it = umap.begin();
	while(it != umap.end()) {// End is after the last element 1,2,3 .. end
		cout<<"Key: "<<it -> first<<"\tValue: "<<it -> second<<endl;
		it++;
	}	

	// find 
	// Returns iterator
	unordered_map<string, int> :: iterator it_umap_find = umap.find("d");
	cout<<"Found: "<<it_umap_find -> first<<"\t"<<it_umap_find -> second<<endl;
	umap.erase(it_umap_find);
	// umap.erase(it_umap_find, it_umap_find + 4); // To delete in range
	// umap.erase(umap.begin(), umap.end());

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	vector<int>::iterator it_vec;

	for(it_vec = v.begin();it_vec != v.end();it_vec++) {
		cout<<*it_vec<<endl;
	}
}
