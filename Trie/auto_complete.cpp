// #include "TrieNode.h"
#include <string>
#include <iostream>
//#include "Trie.h"
#include <vector>
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
    TrieNode* search(TrieNode *root, string word) {
        // cout << root -> data<< ":"<<root -> isTerminal<<endl;
        // Base case
        if(word.size() == 0) {
            // return root -> isTerminal;
            return root;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        } else {
            // If child word[0] is not found return false
            // return false;
            return NULL;
        }

        // Recursive call
        return search(child, word.substr(1));
    }

    // User callable function
    TrieNode* search(string word) {
        return search(root, word);
    }
    
    void allPossibleWords(TrieNode *root, string pattern, string output) {
        // If root itself is terminating node then print
        if(root -> isTerminal == true) {
            cout<<pattern<<output<<endl;
        }
        
        // Explore all possible children
        for(int i=0; i<26;i++) {
            if(root -> children[i] != NULL) {
                int index = i;
                TrieNode *child;
                child = root -> children[index];
                string to_pass = output + child -> data;
                allPossibleWords(child, pattern, to_pass);
            }    
        }
        
        return;
    }
    
    void autoComplete(vector<string> arr, string pattern) {
        // Complete this function
        // Print the output as specified in question
        // Insert word in Trie
        for(int i=0; i<arr.size(); i++) {
            string word = arr[i];
            insertWord(word);
        }
        
        // Search and getback the node where the pattern completes
        TrieNode* match_found_node = search(pattern);
        if(match_found_node == NULL) {
            return;
        } 
        // else {
        //     cout<<match_found_node -> data<<endl;
        // }
        
        // Find and print all possible words in Trie from the given node onwards
        string output = "";
        allPossibleWords(match_found_node, pattern, output);
    }
};

// Main
// Sample Input/ouput
/*
7
do dont no not note notes den
no
----
no
not
note
notes
---

7
do dont no not note notes den
nom
---
<empty>
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
    t.autoComplete(vect, pattern);
}

