#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
  std::string buildString(const std::string& str) {
    // Using std::string as a dynamic char array
    std::string result_s;
    // Iterate through each character in the string
    for (char c : str) {
        if (c == '#') {
            if (!result_s.empty()) {
                result_s.pop_back(); // Remove the last character
            }
        } else {
            result_s.push_back(c); // Append the character
        }
    }
    return result_s;
  }

  bool backspaceCompare(std::string s, std::string t) {
      return buildString(s) == buildString(t);
  }
};

// Example Usage (for testing locally)
int main() {
    Solution sol;

    // Test 1: Basic test, should be equal
    std::string s1 = "ab#c";
    std::string t1 = "ad#c";
    std::cout << "Test 1: " << (sol.backspaceCompare(s1, t1) ? "PASS" : "FAIL") << std::endl; // Expected: PASS

    // Test 2: Should be equal
    std::string s2 = "ab##";
    std::string t2 = "c#d#";
    std::cout << "Test 2: " << (sol.backspaceCompare(s2, t2) ? "PASS" : "FAIL") << std::endl; // Expected: PASS

    // Test 3: Should not be equal
    std::string s3 = "a#c";
    std::string t3 = "b";
    std::cout << "Test 3: " << (sol.backspaceCompare(s3, t3) ? "PASS" : "FAIL") << std::endl; // Expected: FAIL

    // Test 4: Both empty after backspaces
    std::string s4 = "####";
    std::string t4 = "##";
    std::cout << "Test 4: " << (sol.backspaceCompare(s4, t4) ? "PASS" : "FAIL") << std::endl; // Expected: PASS

    // Test 5: No backspaces, not equal
    std::string s5 = "abc";
    std::string t5 = "abd";
    std::cout << "Test 5: " << (sol.backspaceCompare(s5, t5) ? "PASS" : "FAIL") << std::endl; // Expected: FAIL

    // Test 6: No backspaces, equal
    std::string s6 = "abc";
    std::string t6 = "abc";
    std::cout << "Test 6: " << (sol.backspaceCompare(s6, t6) ? "PASS" : "FAIL") << std::endl; // Expected: PASS
    return 0;
}