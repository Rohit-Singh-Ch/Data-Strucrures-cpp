#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;

// /***************
// * Main function - 

// Sample input
// 1 h 1 hello 1 hi 1 the 1 there 1 their 1 those 1 this 2 this 2 th 4 3 this 4 -1 
int main() {
    int choice;
    cin >> choice;
    Trie t;
    
    //cout << "asasas";
    while(choice != -1){
        string word;
        bool ans;
        switch(choice) {
            case 1 : // insert
                // getline(cin, word);
                cin >> word;
                t.insertWord(word);
                break;
            case 2 : // search
                // getline(cin, word);
                cin >> word;
                ans = t.search(word);
                if (ans) {
                    cout << "true" << endl;
                } else {
                    cout << "false" << endl;
                }
                break;
			case 3 : // Remove
                // getline(cin, word);
                cin >> word;
                t.removeWord(word);
                break;

            default :
                return 0;
        }
        cin >> choice;
    }
    return 0;
}
// **************/
