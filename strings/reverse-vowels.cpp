#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
    // Helper function to check if a character is a vowel.
    // We can use a hash set or a simple check for better performance.
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    std::string reverseVowels(std::string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Find the next vowel from the left.
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Find the next vowel from the right.
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // If we found vowels at both ends, and left is still less than right, swap them.
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

// Example Usage (for testing locally)
int main() {
    Solution sol;
    // Test cases for reverseVowels
    std::string test1 = "hello";
    std::cout << "reverseVowels(\"hello\"): " << sol.reverseVowels(test1) << " (expected: holle)" << std::endl;

    std::string test2 = "leetcode";
    std::cout << "reverseVowels(\"leetcode\"): " << sol.reverseVowels(test2) << " (expected: leotcede)" << std::endl;

    std::string test3 = "aA";
    std::cout << "reverseVowels(\"aA\"): " << sol.reverseVowels(test3) << " (expected: Aa)" << std::endl;

    std::string test4 = "bcdfg";
    std::cout << "reverseVowels(\"bcdfg\"): " << sol.reverseVowels(test4) << " (expected: bcdfg)" << std::endl;

    std::string test5 = "";
    std::cout << "reverseVowels(\"\"): " << sol.reverseVowels(test5) << " (expected: )" << std::endl;

    return 0;
}