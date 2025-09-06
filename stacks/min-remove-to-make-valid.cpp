#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::stack<int> st;
        std::unordered_set<int> to_remove;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.empty()) {
                    to_remove.insert(i);
                } else {
                    st.pop();
                }
            }
        }

        while (!st.empty()) {
            to_remove.insert(st.top());
            st.pop();
        }

        std::string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (to_remove.find(i) == to_remove.end()) {
                result += s[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test 1: Basic example
    std::string expr1 = "a)b(c)d";
    std::string result1 = sol.minRemoveToMakeValid(expr1);
    std::cout << "Test 1: " << result1 << " (expected: ab(c)d)" << std::endl;

    // Test 2: Extra opening parentheses
    std::string expr2 = "((a(b(c)d)";
    std::string result2 = sol.minRemoveToMakeValid(expr2);
    std::cout << "Test 2: " << result2 << " (expected: a(b(c)d))" << std::endl;

    // Test 3: Mixed parentheses
    std::string expr3 = "2*(5+5*2)/3+6/2+3";
    std::string result3 = sol.minRemoveToMakeValid(expr3);
    std::cout << "Test 3: " << result3 << " (expected: 2*(5+5*2)/3+6/2+3)" << std::endl;

    // Test 4: All parentheses valid
    std::string expr4 = "(a(b(c)d))";
    std::string result4 = sol.minRemoveToMakeValid(expr4);
    std::cout << "Test 4: " << result4 << " (expected: (a(b(c)d)))" << std::endl;

    // Test 5: No parentheses
    std::string expr5 = "abcde";
    std::string result5 = sol.minRemoveToMakeValid(expr5);
    std::cout << "Test 5: " << result5 << " (expected: abcde)" << std::endl;

    // Test 6: Empty string
    std::string expr6 = "";
    std::string result6 = sol.minRemoveToMakeValid(expr6);
    std::cout << "Test 6: '" << result6 << "' (expected: '')" << std::endl;

    // Test 7: Only closing parentheses
    std::string expr7 = ")))";
    std::string result7 = sol.minRemoveToMakeValid(expr7);
    std::cout << "Test 7: '" << result7 << "' (expected: '')" << std::endl;

    // Test 8: Only opening parentheses
    std::string expr8 = "(((";
    std::string result8 = sol.minRemoveToMakeValid(expr8);
    std::cout << "Test 8: '" << result8 << "' (expected: '')" << std::endl;
    return 0;
}