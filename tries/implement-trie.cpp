#include<iostream>
#include<vector>

using namespace std;
 
struct Node {
  // links to subsequent trie nodes
  Node* links[26] = { NULL };

  // flag to infer if current node is last node of a word
  bool flag = false;

  // checks if the trie node corresponding to given character exists
  bool isCharacterNodePresent(char ch) {
    return (links[ch - 'a'] != NULL);
  }
 
  // to add new trie node corresponding to given character
  void addCharacterNode(char ch, Node *node) {
    links[ch - 'a'] = node;
  }
 
  // to get the trie node corresponding to given character
  Node* getNextNode(char ch) {
    return links[ch - 'a'];
  }
 
  // to set flag to true to mark end of the word
  void setAsEndNode() {
    flag = true;
  }
 
  // to check if a word ends at the current node or not
  bool isEndNode() {
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
        if (node->isCharacterNodePresent(word[i]) == false) {
          node->addCharacterNode(word[i], new Node());
        }
  
        // move to next char reference trie node
        node = node->getNextNode(word[i]);
      }
  
      // once the word ends, mark the current reference trie node as last
      node->setAsEndNode();
    }
  
    bool search(string word) {
      // always start with the root node to start checking if the characters of the given word exists
      Node *node = root;
      for (int i = 0; i < word.size(); i++) {
        if (node->isCharacterNodePresent(word[i]) == false) {
          return false;
        }
  
        // move to next char reference trie node
        node = node->getNextNode(word[i]);
      }
  
      return node->isEndNode();
    }
  
    bool startsWith(string prefix) {
      Node* node = root;
      for (int i = 0; i < prefix.size(); i++) {
        if (!node->isCharacterNodePresent(prefix[i])) {
          return false;
        }
        node = node->getNextNode(prefix[i]);
      }
  
      return true;
    }
};
 
int main() {
  int n = 5;
  // 1. Insert Operation
  // 2. Search Operation
  // 3. Starts With Operation
  vector<int> operationType = { 1, 1, 2, 3, 2 };
  vector<string> operationValue = { "hello", "help", "help", "hel", "hel" };

  // initialize trie
  Trie trie;

  for (int i = 0; i < n; i++) {
    // Insert operation
    if (operationType[i] == 1) {
      cout << "Insert word: " << operationValue[i] << endl;
      trie.insert(operationValue[i]);
    // Search operation
    } else if (operationType[i] == 2) {
      cout << "Search word: " << operationValue[i] << " -> ";
      if (trie.search(operationValue[i])) {
        cout << "found" << "\n";
      } else {
        cout << "false" << "\n";
      }
    // StartsWith Operation
    } else {
      if (trie.startsWith(operationValue[i])) {
        cout << "Check if a word starts with: " << operationValue[i] << " -> ";
        cout << "found" << "\n";
      } else {
        cout << "not found" << "\n";
      }
    }
  }
}
