#include <iostream>
using namespace std;

struct Node {
    Node* links[26] = { NULL };
    // every node holds this count for no of words ends here
    int countEndsWith = 0;
    // every node holds this count for no of words this node is part of its prefix
    int countPrefix = 0;

    // checks if the trie node corresponding to given character exists
    bool isCharacterNodePresent(char ch) {
        return (links[ch - 'a'] != NULL);   
    }

    // to add new trie node corresponding to given character
    void addCharacterNode(char ch) {
        Node *node = new Node();
        links[ch - 'a'] = node;
    }

    // to get the trie node corresponding to given character
    Node* getNextNode(char ch) {
        return links[ch - 'a'];
    }

    void incrementWordCount() {
        countEndsWith++;
    }

    void incrementPrefixCount() {
        countPrefix++;
    }

    void decrementWordCount() {
        countEndsWith--;
    }

    void decrementPrefixCount() {
        countPrefix--;
    }

    int getWordCount() {
        return countEndsWith;
    }

    int getPrefixCount() {
        return countPrefix;
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
            Node *currNode = root;
            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i]) == false) {
                    currNode->addCharacterNode(word[i]);
                }

                currNode = currNode->getNextNode(word[i]);

                // for every insert we increment the prefix count
                currNode->incrementPrefixCount();
            }
            
            // at the end of inserting word, we increment the word count of last node
            currNode->incrementWordCount();
        }
 
        int countWordsEqualTo(string &word) {
            Node *currNode = root;
            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i])) {
                    currNode = currNode->getNextNode(word[i]);
                } else {
                    return 0;
                }
            }
            
            // return the word count of the last node corresponding to given word
            return currNode->getWordCount();
        }

        int countWordsStartingWith(string &word) {
            Node *currNode = root;
            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i])) {
                    currNode = currNode -> getNextNode(word[i]);
                } else {
                    return 0;
                }
            }

            return currNode->getPrefixCount();
        }
 
        void erase(string &word) {
            Node *currNode = root;
            for (int i = 0; i < word.length(); i++) {
                if (currNode->isCharacterNodePresent(word[i])) {
                    currNode = currNode->getNextNode(word[i]);
                    currNode->decrementPrefixCount();
                } else {
                    return;
                }
            }
            currNode->decrementWordCount();
        }
};

int main() {
    // initialize trie
    Trie T;

    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");

    string word1 = "apps";
    cout << "Count of words equal to " << word1 << ": " << T.countWordsEqualTo(word1) << endl;

    string word2 = "abc";
    cout << "Count of words equal to " << word2 << ": " << T.countWordsEqualTo(word2) << endl;

    string word3 = "ap";
    cout << "Count of words starting with " << word3 << ": " << T.countWordsStartingWith(word3) << endl;

    string word4 = "appl";
    cout << "Count of words starting with " << word4 << ": " << T.countWordsStartingWith(word4) << endl;

    T.erase(word1);
    cout << "Count of words equal to " << word1 << ": " << T.countWordsEqualTo(word1) << endl;
    return 0;
}