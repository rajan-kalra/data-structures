#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* links[26] = { NULL };
    bool flag;

    // checks if the trie node corresponding to given character exists
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    // gets the trie node corresponding to given character
    Node* getKeyNode(char ch) {
        return links[ch - 'a'];
    }

    // to add new trie node corresponding to given character
    void addKeyNode(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // to make the node as end node
    void setEnd () {
        flag = true;
    }

    // check if node is end node
    bool isEnd () {
        return flag;
    }
};
 
class Trie {
    private:
        Node* root;
 
    public:
    /* Initialize your data structure here */
    Trie() {
        root = new Node();
    }
 
    /* Inserts a word into the trie */
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i]) == false) {
                node->addKeyNode(word[i], new Node());
            }
            node = node->getKeyNode(word[i]);
        }

        node->setEnd();
    }

    bool checkIfAllPrefixExists (string word) {
        bool f1 = true;
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->getKeyNode(word[i]);
                if (node->isEnd() == false)
                    return false;
            }

            return false;
        }

        return true;
    }
};

string completeString (int n, vector<string>& input) {
    Trie* obj = new Trie();
    for (string &word : input) {
        obj->insert(word);
    }

    string longest;
    for (auto &word: input) {
        if (obj->checkIfAllPrefixExists(word)) {
            if(word.size() > longest.size()) {
                longest = word; 
            } else if(word.size() == longest.size() && word < longest) {
                longest = word; 
            }
        }
    }

    if(longest == "")
        return "None";

    return longest; 
}

int main() {

    return 0;
}