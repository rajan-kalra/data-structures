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
  std::string s = "ab#c";
  std::string t = "ad#c";
  if (sol.backspaceCompare(s, t)) {
      std::cout << "The strings are equal after backspace processing." << std::endl;
  } else {
      std::cout << "The strings are not equal after backspace processing." << std::endl;
  }
  return 0;
}