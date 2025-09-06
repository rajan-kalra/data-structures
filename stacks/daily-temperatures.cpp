#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n, 0);
        std::stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prev_index = s.top();
                s.pop();
                result[prev_index] = i - prev_index;
            }
            s.push(i);
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Example from LeetCode
    std::vector<int> temperatures1 = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result1 = sol.dailyTemperatures(temperatures1);
    std::cout << "Test 1: ";
    for (int i : result1) std::cout << i << " ";
    std::cout << "(expected: 1 1 4 2 1 1 0 0)" << std::endl;

    // Test 2: All increasing
    std::vector<int> temperatures2 = {60, 61, 62, 63};
    std::vector<int> result2 = sol.dailyTemperatures(temperatures2);
    std::cout << "Test 2: ";
    for (int i : result2) std::cout << i << " ";
    std::cout << "(expected: 1 1 1 0)" << std::endl;

    // Test 3: All decreasing
    std::vector<int> temperatures3 = {80, 79, 78, 77};
    std::vector<int> result3 = sol.dailyTemperatures(temperatures3);
    std::cout << "Test 3: ";
    for (int i : result3) std::cout << i << " ";
    std::cout << "(expected: 0 0 0 0)" << std::endl;

    // Test 4: All same
    std::vector<int> temperatures4 = {70, 70, 70, 70};
    std::vector<int> result4 = sol.dailyTemperatures(temperatures4);
    std::cout << "Test 4: ";
    for (int i : result4) std::cout << i << " ";
    std::cout << "(expected: 0 0 0 0)" << std::endl;

    // Test 5: Single element
    std::vector<int> temperatures5 = {100};
    std::vector<int> result5 = sol.dailyTemperatures(temperatures5);
    std::cout << "Test 5: ";
    for (int i : result5) std::cout << i << " ";
    std::cout << "(expected: 0)" << std::endl;

    // Test 6: Empty input
    std::vector<int> temperatures6 = {};
    std::vector<int> result6 = sol.dailyTemperatures(temperatures6);
    std::cout << "Test 6: ";
    for (int i : result6) std::cout << i << " ";
    std::cout << "(expected: )" << std::endl;

    return 0;
}