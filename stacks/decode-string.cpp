#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> num_stack;
        std::stack<std::string> str_stack;
        std::string current_string = "";
        int current_num = 0;

        for (char c : s) {
            // if its a digit, create the complete number
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            // if its a character, add it to the current string
            } else if (isalpha(c)) {
                current_string += c;
            // opening bracket
            } else if (c == '[') {
                // when the '[' is encountered, push the current number onto the stack
                num_stack.push(current_num);
                // when the '[' is encountered, push the current string and reset
                str_stack.push(current_string);
                current_num = 0;
                current_string = "";
            } else if (c == ']') {
                int repeat_times = num_stack.top();
                num_stack.pop();
                std::string prev_string = str_stack.top();
                str_stack.pop();

                std::string temp_string = "";
                for (int i = 0; i < repeat_times; ++i) {
                    temp_string += current_string;
                }
                current_string = prev_string + temp_string;
            }
        }
        return current_string;
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
    std::cout << "Test 8: " << result8 << " (expected: acddddcdddacdddddddacddddddd)" << std::endl;
    return 0;
}