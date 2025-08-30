#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    std::string frequencySort(std::string s) {
        // Step 1: Count character frequencies using a hash map
        std::unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Use a max heap (priority queue)
        std::priority_queue<std::pair<int, char>> max_heap;
        for (auto const& [key, val] : freq) {
            max_heap.push({val, key});
        }

        // Step 3: Build the result string
        std::string result;
        while (!max_heap.empty()) {
            auto [count, ch] = max_heap.top();
            max_heap.pop();
            result += std::string(count, ch);
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::string s1 = "tree";
    std::string result1 = sol.frequencySort(s1);
    std::cout << "Input: " << s1 << ", Sorted: " << result1 << std::endl;

    std::string s2 = "cccaaa";
    std::string result2 = sol.frequencySort(s2);
    std::cout << "Input: " << s2 << ", Sorted: " << result2 << std::endl;

    std::string s3 = "Aabb";
    std::string result3 = sol.frequencySort(s3);
    std::cout << "Input: " << s3 << ", Sorted: " << result3 << std::endl;
    
    return 0;
}