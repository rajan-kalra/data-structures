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
    std::vector<std::pair<std::string, bool>> test_cases = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {"", true},
        {" ", true},
        {"a.", true},
        {"0P", false},
        {"Madam", true},
        {"No lemon, no melon", true},
        {"Was it a car or a cat I saw?", true},
        {"hello", false}
    };

    for (const auto& [input, expected] : test_cases) {
        bool result = solution.isPalindrome(input);
        std::cout << "Input: \"" << input << "\" -> Output: " 
                  << (result ? "true" : "false")
                  << " (expected: " << (expected ? "true" : "false") << ")\n";
    }
    return 0;
}