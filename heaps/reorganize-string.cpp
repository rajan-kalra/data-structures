#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        // Step 1: Count character frequencies
        std::unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
            // Edge case: Check if any character exceeds the half of the string length
            if (counts[c] > (s.length() + 1) / 2) {
                return ""; // Impossible to reorganize
            }
        }

        // Step 2: Use a max-heap of {frequency, character} pairs
        std::priority_queue<std::pair<int, char>> max_heap;
        for (auto const& pair : counts) {
            max_heap.push({pair.second, pair.first});
        }

        // Step 3: Build the result string greedily
        std::string result = "";
        while (max_heap.size() >= 2) {
            std::pair<int, char> p1 = max_heap.top();
            max_heap.pop();
            std::pair<int, char> p2 = max_heap.top();
            max_heap.pop();

            result += p1.second;
            result += p2.second;

            p1.first--;
            p2.first--;

            if (p1.first > 0) {
                max_heap.push(p1);
            }
            if (p2.first > 0) {
                max_heap.push(p2);
            }
        }

        // Step 4: Append the last remaining character if any
        if (!max_heap.empty()) {
            result += max_heap.top().second;
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::string s1 = "aab";
    std::cout << "Input: " << s1 << ", Reorganized: " << sol.reorganizeString(s1) << std::endl; // Expected: "aba"

    std::string s2 = "aaab";
    std::cout << "Input: " << s2 << ", Reorganized: " << sol.reorganizeString(s2) << std::endl; // Expected: ""

    std::string s3 = "vvvlo";
    std::cout << "Input: " << s3 << ", Reorganized: " << sol.reorganizeString(s3) << std::endl; // Expected: "vovlv" (or similar)

    std::string s4 = "reorganizedstring";
    std::cout << "Input: " << s4 << ", Reorganized: " << sol.reorganizeString(s4) << std::endl; 
    
    return 0;
}