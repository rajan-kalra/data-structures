#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
  std::string licenseKeyFormatting(std::string s, int k) {
    std::string ans = "";
    int char_count = 0; // Counts characters in the current group

    // Iterate from the end of the original string
    for (int i = s.length() - 1; i >= 0; --i) {
      // Skip the dashes
      if (s[i] == '-') {
          continue;
      }

      // If a group of k characters is formed, add a dash (unless it's the very first group being formed)
      if (char_count > 0 && char_count % k == 0) {
          ans += '-';
      }

      // Convert to uppercase and append the character
      ans += std::toupper(s[i]);
      char_count++;
    }

    // The string was built in reverse, so reverse it back
    std::reverse(ans.begin(), ans.end());

    return ans;
  }
};

// Example Usage (for testing locally)
int main() {
  Solution sol;
  std::string s = "2-5g-3-J";
  int k = 2;
  std::string formattedKey = sol.licenseKeyFormatting(s, k);
  std::cout << "Formatted License Key: " << formattedKey << std::endl;
  // Expected output: "2-5G-3J"
    
  return 0;
}