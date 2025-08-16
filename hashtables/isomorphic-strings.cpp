#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        // EDGE CASE: Check if the lengths of the strings are equal
        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> s_to_t(256, 0); // Map s characters to t characters
        std::vector<int> t_to_s(256, 0); // Map t characters to s characters

        for (int i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            // Check s_to_t mapping
            if (s_to_t[char_s] == 0) {
                // No mapping exists, create one
                s_to_t[char_s] = char_t;
            } else if (s_to_t[char_s] != char_t) {
                // Existing mapping is inconsistent
                return false;
            }

            // Check t_to_s mapping (reverse)
            if (t_to_s[char_t] == 0) {
                // No mapping exists, create one
                t_to_s[char_t] = char_s;
            } else if (t_to_s[char_t] != char_s) {
                // Existing reverse mapping is inconsistent
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test 1: Isomorphic strings
    std::string s1 = "egg";
    std::string t1 = "add";
    std::cout << "Test 1: " << (sol.isIsomorphic(s1, t1) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    // Test 2: Not isomorphic
    std::string s2 = "foo";
    std::string t2 = "bar";
    std::cout << "Test 2: " << (sol.isIsomorphic(s2, t2) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    // Test 3: Isomorphic with different characters
    std::string s3 = "paper";
    std::string t3 = "title";
    std::cout << "Test 3: " << (sol.isIsomorphic(s3, t3) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    // Test 4: Different lengths
    std::string s4 = "ab";
    std::string t4 = "a";
    std::cout << "Test 4: " << (sol.isIsomorphic(s4, t4) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    // Test 5: Both empty strings
    std::string s5 = "";
    std::string t5 = "";
    std::cout << "Test 5: " << (sol.isIsomorphic(s5, t5) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    // Test 6: Single character
    std::string s6 = "a";
    std::string t6 = "b";
    std::cout << "Test 6: " << (sol.isIsomorphic(s6, t6) ? "PASS" : "FAIL") << " (expected: PASS)" << std::endl;

    // Test 7: Repeated characters, not isomorphic
    std::string s7 = "ab";
    std::string t7 = "aa";
    std::cout << "Test 7: " << (sol.isIsomorphic(s7, t7) ? "PASS" : "FAIL") << " (expected: FAIL)" << std::endl;

    return 0;
}