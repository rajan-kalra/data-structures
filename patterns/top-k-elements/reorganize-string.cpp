#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        // Step 1: Count character frequencies
        std::unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Build the max-heap (priority_queue)
        // Stores pairs of (frequency, character)
        std::priority_queue<std::pair<int, char>> pq;
        for (auto const& [key, val] : freqMap) {
            // Step 3: Check for impossible case
            if (val > (s.length() + 1) / 2) {
                return "";
            }
            pq.push({val, key});
        }

        // Step 4: Reconstruct the string
        std::string result = "";
        while (pq.size() >= 2) {
            std::pair<int, char> p1 = pq.top();
            pq.pop();
            std::pair<int, char> p2 = pq.top();
            pq.pop();

            result += p1.second;
            result += p2.second;

            if (--p1.first > 0) {
                pq.push(p1);
            }
            if (--p2.first > 0) {
                pq.push(p2);
            }
        }
        
        // Step 5: Handle the last character if any
        if (!pq.empty()) {
            result += pq.top().second;
        }

        return result;
    }
};
  
int main() {
    Solution solution;
    std::string input = "aabbcc";
    std::string output = solution.reorganizeString(input);
    std::cout << "Reorganized string: " << output << std::endl; // Example output: "abcabc" or any valid rearrangement
    return 0;
}