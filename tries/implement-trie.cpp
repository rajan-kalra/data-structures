#include<iostream>
#include<vector>
 
class Node {
    Node* links[26] = { nullptr };
    bool flag = false;

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

    // to set flag to true to mark end of the word
    void setEnd() {
        flag = true;
    }

    // to check if a word ends at the current node or not
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

        void insert (const std::string& word) {
            // always start with the root node to start inserting the characters
            Node *currNode = root;

            for (char ch : word) {
                // current char doesn't have the corresponding reference trie node
                if (currNode->has(ch) == false) {
                    currNode->add(ch);
                }

                // move to next char reference trie node
                currNode = currNode->get(ch);
            }

            // once the word ends, mark the current reference trie node as last
            currNode->setEnd();
        }

        bool search(const std::string& word) {
            // always start with the root node to start checking if the characters of the given word exists
            Node *currNode = root;

            for (char ch : word) {
                if (currNode->has(ch) == false) {
                    return false;
                }

                // move to next char reference trie node
                currNode = currNode->get(ch);
            }

            return currNode->isEnd();
        }

        bool startsWith(const std::string& prefix) {
            Node* currNode = root;
            for (char ch : prefix) {
                if (!currNode->has(ch)) {
                    return false;
                }
                currNode = currNode->get(ch);
            }

            return true;
        }
};
 
int main() {
    int n = 5;
    // 1. Insert Operation
    // 2. Search Operation
    // 3. Starts With Operation
    std::vector<int> operationType = { 1, 1, 2, 3, 2 };
    std::vector<std::string> operationValue = { "hello", "help", "help", "hel", "hel" };

    // initialize trie
    Trie trie;

    for (int i = 0; i < n; i++) {
        // Insert operation
        if (operationType[i] == 1) {
            std::cout << "Insert word: " << operationValue[i] << std::endl;
            trie.insert(operationValue[i]);
        // Search operation
        } else if (operationType[i] == 2) {
            std::cout << "Search word: " << operationValue[i] << " -> ";
            if (trie.search(operationValue[i])) {
                std::cout << "found" << "\n";
            } else {
                std::cout << "false" << "\n";
            }
        // StartsWith Operation
        } else {
            if (trie.startsWith(operationValue[i])) {
                std::cout << "Check if a word starts with: " << operationValue[i] << " -> ";
                std::cout << "found" << "\n";
            } else {
                std::cout << "not found" << "\n";
            }
        }
    }
}
