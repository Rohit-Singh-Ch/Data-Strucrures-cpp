// #include "TrieNode.h"
#include <string>
#include <vector>
#include <iostream>
//#include "Trie.h"
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

    	// Search
    // Internal helper search function
    bool search(TrieNode *root, string word) {
        // cout << root -> data<< ":"<<root -> isTerminal<<endl;
        // Base case
        if(word.size() == 0) {
            // return root -> isTerminal;
            // For pattern search it does not matter if isTerminal is true, 
            // so we can simply return true if we reach word.size() == 0
            return true;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            // If child word[0] is not found return false
            return false;
        }

        // Recursive call
        return search(child, word.substr(1));
    }

    // User callable function
    bool search(string word) {
        return search(root, word);
    }
    
	bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
        // Insert all suffixes
    	for(int i = 0; i<vect.size();i++) {
            string word = vect.at(i);
            for(int j = 0; j<word.length(); j++) {
                // cout<<"DEBUG: "<<word.substr(j)<<endl;
                insertWord(word.substr(j));
            }
            // cout<<endl;
        }
        
        return search(pattern);
    }
};

// Sample input
/* 
4
abc def ghi cba
de

output: true
*/

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    if (t.patternMatching(vect, pattern)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
