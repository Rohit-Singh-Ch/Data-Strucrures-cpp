#include <iostream>
#include <string>
//#include "Trie.h"
#include <vector>
#include <algorithm> // For string reverse
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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


	

	bool findIfPalindromePair(vector<string> arr) {
		// Complete this function
		// Return true or false.
        // Insert word rin Trie
        for(int i=0; i<arr.size(); i++) {
            string word = arr[i];
            insertWord(word);
        }
        
        // For each word check for palindrome pair
        for(int i=0; i<arr.size(); i++) {
            string word = arr[i];
            string rev = word;
            
            // Inbuilt reverse function from algorithm, reverse inplace
            reverse(rev.begin(), rev.end());
            // cout<<"word is: "<<word<<endl;
            // cout<<"palindrome pair1: "<<rev<<endl;
            // cout<<"palindrome pair2: "<<rev.substr(1)<<endl;
            // cout<<endl;
            bool res1 = search(rev);
            bool res2 = search(rev.substr(1));
            // Return if you find any palindrome pair
            bool res = res1 || res2;
            if(res == true) {
                return res;
            }
        }
        return false;
	}
};


// Sample input
/*
4
abc def ghi cba

output - true
// abc and cba
4
abc def ghi hg

output - true
// "ghi" and "hg" forms a palindrome

3
bat mat cat

output - false
*/
int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}
