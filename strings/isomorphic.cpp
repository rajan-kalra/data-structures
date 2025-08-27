#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> map_s_to_t;
    std::unordered_map<char, char> map_t_to_s;

    for (int i = 0; i < s.length(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        // Check the forward mapping from s to t
        if (map_s_to_t.find(char_s) != map_s_to_t.end() && map_s_to_t[char_s] != char_t) {
            return false; // Inconsistent mapping
        }

        if (map_t_to_s.find(char_t) != map_t_to_s.end() && map_t_to_s[char_t] != char_s) {
            return false; // Inconsistent mapping
        }

        map_s_to_t[char_s] = char_t;
        map_t_to_s[char_t] = char_s;
    }

    return true;
}
};

// Example Usage (for testing locally)
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