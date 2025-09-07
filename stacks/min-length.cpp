#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> st;
        for (char c : s) {
            if (!st.empty()) {
                char last_char = st.top();
                if ((last_char == 'A' && c == 'B') || (last_char == 'C' && c == 'D')) {
                    st.pop();
                } else {
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        return st.size();
    }

    /*
     * std::string is often slightly faster than std::stack<char> because:
     * 1. std::string stores data contiguously in memory, which can be more cache-friendly.
     * 2. std::stack<char> is typically implemented as a wrapper over std::deque<char>, which may have slightly more overhead.
     * 3. std::string is more idiomatic for problems where you need to build or modify a string.
     */
    int minLengthOptimized(std::string s) {
        std::string result;
        for (char c : s) {
            if (!result.empty()) {
                char last_char = result.back();
                if ((last_char == 'A' && c == 'B') || (last_char == 'C' && c == 'D')) {
                    result.pop_back();
                } else {
                    result.push_back(c);
                }
            } else {
                result.push_back(c);
            }
        }
        return result.length();
    }
};

int main() {
    Solution sol;

    // Test 1: Basic example
    std::string s1 = "ABFCACDB";
    int result1 = sol.minLength(s1);
    std::cout << "Test 1: " << result1 << " (expected: 2)" << std::endl;

    // Test 2: No possible reductions
    std::string s2 = "AFCAD";
    int result2 = sol.minLength(s2);
    std::cout << "Test 2: " << result2 << " (expected: 5)" << std::endl;

    // Test 3: All characters can be removed
    std::string s3 = "ABCDABCD";
    int result3 = sol.minLength(s3);
    std::cout << "Test 3: " << result3 << " (expected: 0)" << std::endl;

    // Test 4: Mixed characters with some reductions
    std::string s4 = "AABCCDBD";
    int result4 = sol.minLength(s4);
    std::cout << "Test 4: " << result4 << " (expected: 4)" << std::endl;

    // Test 5: Single character
    std::string s5 = "A";
    int result5 = sol.minLength(s5);
    std::cout << "Test 5: " << result5 << " (expected: 1)" << std::endl;

    // Test 6: Empty string
    std::string s6 = "";
    int result6 = sol.minLength(s6);
    std::cout << "Test 6: " << result6 << " (expected: 0)" << std::endl;

    // Test 7: Long string with no reductions
    std::string s7(1000, 'A'); // String of 1000 'A's
    int result7 = sol.minLength(s7);
    std::cout << "Test 7: " << result7 << " (expected: 1000)" << std::endl;

    // Test 8: Long string with maximum reductions
    std::string s8;
    for (int i = 0; i < 500; ++i) {
        s8 += "ABCD"; // Repeating pattern that can be fully reduced
    }
    int result8 = sol.minLength(s8);
    std::cout << "Test 8: " << result8 << " (expected: 0)" << std::endl;
    return 0;
}