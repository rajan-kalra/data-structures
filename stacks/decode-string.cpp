#include <iostream>
#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<char> stack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                stack.push(s[i]);
            } else {
                // Build substring until we find '['
                std::string substr = "";
                while (!stack.empty() && stack.top() != '[') {
                    substr = stack.top() + substr;
                    stack.pop();
                }
                
                // Pop the '['
                if (!stack.empty()) {
                    stack.pop();
                }
                
                // Extract the number
                std::string k = "";
                while (!stack.empty() && std::isdigit(stack.top())) {
                    k = stack.top() + k;
                    stack.pop();
                }
                
                // Convert k to integer and repeat substr
                int count = std::stoi(k);
                std::string repeated = "";
                for (int j = 0; j < count; j++) {
                    repeated += substr;
                }
                
                // Push each character of repeated string back to stack
                for (char c : repeated) {
                    stack.push(c);
                }
            }
        }
        
        // Build final result from stack
        std::string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Basic example
    std::string expr1 = "3[a]2[bc]";
    std::string result1 = sol.decodeString(expr1);
    std::cout << "Test 1: " << result1 << " (expected: aaabcbc)" << std::endl;

    // Test 2: Nested example
    std::string expr2 = "3[a2[c]]";
    std::string result2 = sol.decodeString(expr2);
    std::cout << "Test 2: " << result2 << " (expected: accaccacc)" << std::endl;

    // Test 3: More complex nesting
    std::string expr3 = "2[abc]3[cd]ef";
    std::string result3 = sol.decodeString(expr3);
    std::cout << "Test 3: " << result3 << " (expected: abcabccdcdcdef)" << std::endl;

    // Test 4: Single character with multiple repeats
    std::string expr4 = "10[a]";
    std::string result4 = sol.decodeString(expr4);
    std::cout << "Test 4: " << result4 << " (expected: aaaaaaaaaa)" << std::endl;

    // Test 5: No brackets, just a string
    std::string expr5 = "abcde";
    std::string result5 = sol.decodeString(expr5);
    std::cout << "Test 5: " << result5 << " (expected: abcde)" << std::endl;

    // Test 6: Empty string
    std::string expr6 = "";
    std::string result6 = sol.decodeString(expr6);
    std::cout << "Test 6: '" << result6 << "' (expected: '')" << std::endl;

    // Test 7: Nested with different characters
    std::string expr7 = "2[3[a]b]";
    std::string result7 = sol.decodeString(expr7);
    std::cout << "Test 7: " << result7 << " (expected: aaabaaab)" << std::endl;

    // Test 8: Complex nested structure
    std::string expr8 = "3[a2[c4[d]]]";
    std::string result8 = sol.decodeString(expr8);
    std::cout << "Test 8: " << result8 << " (expected: acdddcdddacddddcdddacddddcddd)" << std::endl;
    
    return 0;
}