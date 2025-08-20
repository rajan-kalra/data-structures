#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
#include <vector>

bool canPermutePalindrome(std::string s) {
    std::unordered_map<char, int> charCounts;
    for (char c : s) {
        if (std::isalpha(c)) {
            charCounts[std::tolower(c)]++;
        }
    }
    
    int oddCount = 0;
    for (auto const& pair : charCounts) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }
    
    return oddCount <= 1;
}


int main() {
    std::vector<std::string> testInputs = {
        "Tact Coa",      // True: "taco cat", "atco cta"
        "racecar",       // True: already a palindrome
        "aabbcc",        // True: can be rearranged to "abccba"
        "abc",           // False: no permutation is a palindrome
        "aabbc",         // True: "abcba"
        "aabbcd",        // False
        "",              // True: empty string is a palindrome
        "A man a plan a canal Panama", // True: can be rearranged to palindrome
        "No lemon, no melon",          // True
        "xyz"            // False
    };

    std::vector<bool> expected = {
        true, true, true, false, true, false, true, true, true, false
    };

    for (size_t i = 0; i < testInputs.size(); ++i) {
        bool result = canPermutePalindrome(testInputs[i]);
        std::cout << "Test " << (i + 1) << ": \"" << testInputs[i] << "\" -> "
                  << (result ? "True" : "False")
                  << " (expected: " << (expected[i] ? "True" : "False") << ")"
                  << std::endl;
    }

    return 0;
}