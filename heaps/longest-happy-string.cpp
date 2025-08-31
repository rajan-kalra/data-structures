#include <iostream>
#include <string>
#include <vector>
#include <queue>

class Solution {
public:
    std::string longestHappyString(int a, int b, int c) {
        std::string result = "";
        
        // Max-heap to store {count, character}
        std::priority_queue<std::pair<int, char>> max_heap;
        if (a > 0)
            max_heap.push({a, 'a'});
        if (b > 0)
            max_heap.push({b, 'b'});
        if (c > 0)
            max_heap.push({c, 'c'});

        while (!max_heap.empty()) {
            std::pair<int, char> p1 = max_heap.top();
            max_heap.pop();
            
            // Check for consecutive characters
            if (result.size() >= 2 && result[result.size() - 1] == p1.second && result[result.size() - 2] == p1.second) {
                // Must use the next most frequent character
                if (max_heap.empty()) {
                    break; // No other characters available
                }
                std::pair<int, char> p2 = max_heap.top();
                max_heap.pop();
                
                result += p2.second;
                p2.first--;
                if (p2.first > 0) {
                    max_heap.push(p2);
                }
                
                max_heap.push(p1); // Put the first one back
            } else {
                // Add up to two instances of the most frequent character
                int times_to_add = 1;
                if (!max_heap.empty() && p1.first >= max_heap.top().first * 2) {
                    times_to_add = 2;
                }
                if (p1.first >= 2 && (max_heap.empty() || p1.first > max_heap.top().first)) {
                    times_to_add = 2;
                }
                
                for(int i = 0; i < times_to_add && p1.first > 0; ++i) {
                    result += p1.second;
                    p1.first--;
                }
                if (p1.first > 0) {
                    max_heap.push(p1);
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::cout << "a=1, b=1, c=7: " << sol.longestHappyString(1, 1, 7) << std::endl; // Expected: "ccaccbcc" (or similar)
    std::cout << "a=2, b=2, c=1: " << sol.longestHappyString(2, 2, 1) << std::endl; // Expected: "ababc" (or similar)
    std::cout << "a=7, b=1, c=0: " << sol.longestHappyString(7, 1, 0) << std::endl; // Expected: "aabaa" (or similar)
    
    return 0;
}