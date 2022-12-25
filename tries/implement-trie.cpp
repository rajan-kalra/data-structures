#include<iostream>
#include<vector>

using namespace std;
 
struct Node {
	// links to subsequent trie nodes
	Node* links[26];
	bool flag = false;
 
	// checks if the corresponding trie node exists or not
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
 
	// creating reference trie
	void putKey(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
 
	// to get the next node for traversal
	Node* get(char ch) {
		return links[ch - 'a'];
	}
 
	// to set flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
 
	// to check if the word ends at the current node or not
	bool isEnd() {
		return flag;
	}
};
 
class Trie {
private:
	Node* root;
 
public:
	// constructor
	Trie() {
		root = new Node();
	}
 
	void insert (string word) {
		// always start with the root node to start inserting the characters
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			// current key/char doesn't have the corresponding reference trie node
			if (node->containsKey(word[i]) == false) {
				node->putKey(word[i], new Node());
			}
 
			// move to next char reference trie node
			node = node->get(word[i]);
		}
 
		// once the word ends, mark the current reference trie node as last
		node->setEnd();
	}
 
	bool search(string word) {
		// always start with the root node to start checking if the characters of the given word exists
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node->containsKey(word[i]) == false) {
				return false;
			}
 
			// move to next char reference trie node
			node = node->get(word[i]);
		}
 
		return node->isEnd();
	}
 
	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
 
		return true;
	}
};
 
int main() {
  int n = 5;
	vector<int> type = { 1, 1, 2, 3, 2 };
	vector<string> value = { "hello", "help", "help", "hel", "hel" };
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}