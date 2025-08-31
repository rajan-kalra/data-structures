#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

// TrieNode structure
struct TrieNode {
    TrieNode* children[26] = { nullptr };
    bool isEndOfWord = false;
};

class Solution {
private:
    TrieNode* root;

    // Helper function to insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children[ch - 'a'] == nullptr) {
                current->children[ch - 'a'] = new TrieNode();
            }
            current = current->children[ch - 'a'];
        }
        current->isEndOfWord = true;
    }

public:
    Solution() {
        root = new TrieNode();
    }
    
    std::vector<std::vector<int>> indexPairs(std::string text, std::vector<std::string>& words) {
        // Step 1: Build the Trie from the words list
        for (const std::string& word : words) {
            insert(word);
        }

        std::vector<std::vector<int>> result;
        int n = text.length();

        // Step 2: Search the text string for word occurrences
        for (int i = 0; i < n; ++i) {
            TrieNode* current = root;
            for (int j = i; j < n; ++j) {
                char ch = text[j];
                int idx = ch - 'a';
                if (idx < 0 || idx >= 26) break;
                // If character is not in the Trie, break the search from this starting point
                if (current->children[idx] == nullptr) {
                    break;
                }

                current = current->children[idx];

                // If the current node marks the end of a word, add the pair to the result
                if (current->isEndOfWord) {
                    result.push_back({i, j});
                }
            }
        }

        // Step 3: The result is already sorted due to the nature of the loops
        return result;
    }
};

void printResult(const std::vector<std::vector<int>>& pairs) {
    std::cout << "[";
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "[" << pairs[i][0] << ", " << pairs[i][1] << "]";
        if (i < pairs.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;
    std::string text1 = "thestoryofleetcodeandme";
    std::vector<std::string> words1 = {"story", "fleet", "leetcode"};
    std::vector<std::vector<int>> result1 = sol.indexPairs(text1, words1);
    std::cout << "For text=\"" << text1 << "\" and words={\"story\", \"fleet\", \"leetcode\"}, result: ";
    printResult(result1); // Expected: [[3, 7], [9, 13], [10, 17]]

    std::string text2 = "ababa";
    std::vector<std::string> words2 = {"aba", "ab"};
    std::vector<std::vector<int>> result2 = sol.indexPairs(text2, words2);
    std::cout << "For text=\"" << text2 << "\" and words={\"aba\", \"ab\"}, result: ";
    printResult(result2); // Expected: [[0, 1], [0, 2], [2, 3], [2, 4]]
    
    return 0;
}