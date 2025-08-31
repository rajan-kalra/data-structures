#include <iostream>

class Node {
    private:
        Node* links[26] = { nullptr };
        // every node holds this count for no of words ends here
        int countEndsWith = 0;
        // every node holds this count for no of words this node is part of its prefix
        int countPrefix = 0;

    public:
        // checks if the trie node corresponding to given character exists
        bool has(char ch) {
            return (links[ch - 'a'] != nullptr);   
        }

        // to add new trie node corresponding to given character
        void add(char ch) {
            Node *node = new Node();
            links[ch - 'a'] = node;
        }

        // to get the trie node corresponding to given character
        Node* get(char ch) {
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
        void insert(const std::string& word) {
            // always start with the root node to start inserting the characters
            Node *currNode = root;

            for (char ch : word) {
                if (currNode->has(ch) == false) {
                    currNode->add(ch);
                }

                currNode = currNode->get(ch);

                // for every insert we increment the prefix count
                currNode->incrementPrefixCount();
            }
            
            // at the end of inserting word, we increment the word count of last node
            currNode->incrementWordCount();
        }

        int countWordsEqualTo(const std::string &word) {
            Node *currNode = root;
            for (char ch : word) {
                if (currNode->has(ch)) {
                    currNode = currNode->get(ch);
                } else {
                    return 0;
                }
            }
            
            // return the word count of the last node corresponding to given word
            return currNode->getWordCount();
        }

        int countWordsStartingWith(const std::string &word) {
            Node *currNode = root;
            for (char ch : word) {
                if (currNode->has(ch)) {
                    currNode = currNode->get(ch);
                } else {
                    return 0;
                }
            }

            return currNode->getPrefixCount();
        }

        void erase(const std::string &word) {
            Node *currNode = root;
            for (char ch : word) {
                if (currNode->has(ch)) {
                    currNode = currNode->get(ch);
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

    std::string word1 = "apps";
    std::cout << "Count of words equal to " << word1 << ": " << T.countWordsEqualTo(word1) << std::endl;

    std::string word2 = "abc";
    std::cout << "Count of words equal to " << word2 << ": " << T.countWordsEqualTo(word2) << std::endl;

    std::string word3 = "ap";
    std::cout << "Count of words starting with " << word3 << ": " << T.countWordsStartingWith(word3) << std::endl;

    std::string word4 = "appl";
    std::cout << "Count of words starting with " << word4 << ": " << T.countWordsStartingWith(word4) << std::endl;

    std::cout << "Remove: " << word1 << std::endl;
    T.erase(word1);
    std::cout << "Count of words equal to " << word1 << ": " << T.countWordsEqualTo(word1) << std::endl;
    return 0;
}