#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    TrieNode* links[26] = { nullptr };
    int pass_count = 0; // Number of words passing through this node
};

class Solution {
private:
    TrieNode* root;

public:
    Solution() {
        root = new TrieNode();
    }

    // Inserts a string into the Trie
    void insert(const std::string& word) {
        TrieNode* node = root;
        node->pass_count++; // increment for root
        for (char ch : word) {
            if (node->links[ch - 'a'] == nullptr) {
                node->links[ch - 'a'] = new TrieNode();
            }
            node = node->links[ch - 'a'];
            node->pass_count++;
        }
    }

    // Finds the longest common prefix
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Check if the input vector is empty
        if (strs.empty()) {
            return "";
        }
        
        // Build the Trie from all strings
        for (const std::string& s : strs) {
            insert(s);
        }

        std::string lcp = "";
        TrieNode* node = root;
        int total_words = strs.size();

        while (node) {
            // Check if there is only one child node and it has been passed by all words
            if (node->pass_count == total_words) {
                int child_count = 0;
                int child_idx = -1;
                for (int i = 0; i < 26; ++i) {
                    if (node->links[i] != nullptr) {
                        ++child_count;
                        child_idx = i;
                    }
                }
                if (child_count == 1) {
                    lcp += ('a' + child_idx);
                    node = node->links[child_idx];
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return lcp;
    }
};

int main() {
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    Solution sol1;
    std::string result1 = sol1.longestCommonPrefix(strs1);
    std::cout << "Longest Common Prefix for {\"flower\", \"flow\", \"flight\"}: " << result1 << std::endl; // Expected: "fl"

    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    Solution sol2;
    std::string result2 = sol2.longestCommonPrefix(strs2);
    std::cout << "Longest Common Prefix for {\"dog\", \"racecar\", \"car\"}: " << result2 << std::endl; // Expected: ""

    return 0;
}