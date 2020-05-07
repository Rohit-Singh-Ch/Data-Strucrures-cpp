#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> umap; //Template <T>(key, value)
	// insert
	pair<string, int> p("abc", 1);
	umap.insert(p); // Method 1
	umap["def"] = 2; // Method 2

	//find or access
	cout << umap["abc"] << endl;	
	cout << umap.at("abc") << endl;

	// cout << umap.at("ghi"); // Throws "out_of_range" error if key not found
	cout <<"size : " << umap.size()<<endl;
	cout << umap["ghi"] << endl; // Insert default value 0 if key not found, NO ERROR!
	cout <<"size : " << umap.size()<<endl;
	
	// check presense
	if(umap.count("ghi") > 0) { // Count can be 0 or 1, i.e. absent/present
		cout << "ghi is present" << endl;
	}	

	// Erase
	umap.erase("ghi");
	if(umap.count("ghi") > 0) { // Count can be 0 or 1, i.e. absent/present
        cout << "ghi is present" << endl;
    } else {
        cout << "ghi NOT present" << endl;
	}

	return 0;
}
