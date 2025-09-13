#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer past non-alphanumeric characters
            // & stop at the first alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            // Move right pointer past non-alphanumeric characters
            // & stop at the first alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare characters after converting to lowercase
            // the first non-matching pair means it's not a palindrome
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            // Move pointers inward
            left++;
            right--;
        }

        return true;
    }
};

int main() {
  Solution solution;
  std::string s = "A man, a plan, a canal: Panama";
  if (solution.isPalindrome(s)) {
      std::cout << "\"" << s << "\" is a palindrome." << std::endl;
  } else {
      std::cout << "\"" << s << "\" is not a palindrome." << std::endl;
  }
  return 0;
}