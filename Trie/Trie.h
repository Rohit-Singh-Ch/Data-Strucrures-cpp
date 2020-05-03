#include "TrieNode.h"
using namespace std;

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
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
        insertWord(child, word.substr(1));
    }
    
    // For user
    void insertWord(string word) {
        insertWord(root, word);
    }
    
    // Internal helper search function
    bool search(TrieNode *root, string word) {
        // cout << root -> data<< ":"<<root -> isTerminal<<endl;
        // Base case
        if(word.size() == 0) {   
            return root -> isTerminal;
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


	// Remove
	// Internal helper removeWord function
	void removeWord(TrieNode *root, string word) {
		// Base case
        if(word.size() == 0) {
            root -> isTerminal = false;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            // If child word[0] is not found return
            return;
		}

        // Recursive call
        removeWord(child, word.substr(1));
		// To delete the node check if it is useless conditions
			// 1. isTerminal == false
			// 2. child -> children are all null
		if(child -> isTerminal == false) {
			for(int i = 0; i<26; i++) {
				if(child -> children[i] != NULL) {
					// It means the node is not useless so just retrun wtihout deleting
					return;
				}
			}
			// If loop ended without return it means we can deallocate the node
			delete child;
			// Update the link
			root -> children[index] = NULL;
		}
	}

	void removeWord(string word) {
		removeWord(root, word);
	}
};
