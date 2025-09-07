#include <string>
#include <iostream>
#include <stack>
#include <vector>

std::string removeDuplicates(std::string& s) {
    std::string result;
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    return result;
}

std::string removeDuplicatesWithStack(std::string& s) {
    // Using stack to store characters
    std::stack<char> st;

    for (char c : s) {
        // If the stack is not empty and the top of the stack is the same as current character, pop it from the stack
        if (!st.empty() && st.top() == c) {
            st.pop();
        // If the stack is empty or if the top of the stack is not the same as current character, push it onto the stack
        } else {
            st.push(c);
        }
    }

    // Build the result from the stack
    std::string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // The stack builds the string in reverse order
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::vector<std::pair<std::string, std::string>> test_cases = {
        {"abbaca",    "ca"},
        {"azxxzy",    "ay"},
        {"aabbcc",    ""},
        {"abcddcba",  ""},
        {"a",         "a"},
        {"",          ""},
        {"aabbaa",    ""},
        {"abccba",    ""},
        {"aabbccddeeff", ""},
        {"abcd",      "abcd"},
    };

    std::cout << "Testing removeDuplicates:\n";
    for (const auto& [input, expected] : test_cases) {
        std::string s = input;
        std::string output = removeDuplicates(s);
        std::cout << "Input: \"" << input << "\" -> Output: \"" << output << "\" (expected: \"" << expected << "\")\n";
    }

    std::cout << "\nTesting removeDuplicatesWithStack:\n";
    for (const auto& [input, expected] : test_cases) {
        std::string s = input;
        std::string output = removeDuplicatesWithStack(s);
        std::cout << "Input: \"" << input << "\" -> Output: \"" << output << "\" (expected: \"" << expected << "\")\n";
    }

    return 0;
}