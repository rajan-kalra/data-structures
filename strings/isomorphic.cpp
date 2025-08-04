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
        if (map_s_to_t.count(char_s)) {
            if (map_s_to_t[char_s] != char_t) {
                return false;
            }
        } else {
            // If no forward mapping exists, check if reverse mapping already exists
            if (map_t_to_s.count(char_t)) {
                return false; // This means char_t is already mapped from a different char_s
            }
            map_s_to_t[char_s] = char_t;
            map_t_to_s[char_t] = char_s;
        }
    }

    return true;
}
};

// Example Usage (for testing locally)
int main() {
  Solution sol;
  std::string s = "ab#c";
  std::string t = "ad#c";
  if (sol.isIsomorphic(s, t)) {
      std::cout << "The strings are isomorphic." << std::endl;
  } else {
      std::cout << "The strings are not isomorphic." << std::endl;
  }
  return 0;
}