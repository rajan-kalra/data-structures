#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node* links[26] = { NULL };
    bool flag;

    // checks if the trie node corresponding to given character exists
    bool isCharacterNodePresent(char ch) {
        return links[ch - 'a'];
    }

    // gets the trie node corresponding to given character
    Node* getNextNode(char ch) {
        return links[ch - 'a'];
    }

    // to add new trie node corresponding to given character
    void addKeyNode(char ch) {
        Node *node = new Node();
        links[ch - 'a'] = node;
    }

    // to make the node as end node
    void setAsEndNode () {
        flag = true;
    }

    // check if node is end node
    bool isEndNode () {
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
            Node* currNode = root;
            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i]) == false) {
                    currNode->addKeyNode(word[i]);
                }
                currNode = currNode->getNextNode(word[i]);
            }

            currNode->setAsEndNode();
        }

        bool checkIfAllPrefixExists (string word) {
            bool f1 = true;
            Node* currNode = root;

            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i])) {
                    currNode = currNode->getNextNode(word[i]);
                    if (currNode->isEndNode() == false)
                        return false;
                }

                return false;
            }

            return true;
        }
};

string completeString (int n, vector<string>& input) {
    Trie* obj = new Trie();
    // creating trie from all the words in input vector
    for (string &word : input) {
        obj->insert(word);
    }

    string longest;
    for (auto &word: input) {
        // for each word check if all the prefixes in the word exists
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