#include <iostream>
#include "MyMap.h"
using namespace std;

int main() {
	MyMap<int> map;
	// Test insert function
	for(int i = 0; i < 10;i++) {
		char c = '0' + i;// ASCII value will increment, so char will update 0,1,2 ..
		string key = "abc";
		key = key + c;
	
		int value = i + 1;
		map.insert(key, value);
		cout << map.size() << "\t" << map.getLoadFactor()<<endl;
	}

	cout <<"size:\t"<<map.size() << endl;
	//Test remove function
	cout<<endl;
	cout<<"removing abc2:\t"<<map.remove("abc2")<<endl;
	cout<<"removing abc7:\t"<<map.remove("abc7")<<endl;
	cout<<endl;
	
	for(int i = 0; i < 10;i++) {
        char c = '0' + i;// ASCII value will increment, so char will update 0,1,2 ..
        string key = "abc";
        key = key + c;

        cout<<key<<":\t"<<map.getValue(key)<<endl;
    }

	cout <<"size:\t"<<map.size() << endl;
}
