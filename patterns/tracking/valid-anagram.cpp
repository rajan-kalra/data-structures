#include <iostream>
#include <string>
#include <vector>

bool isAnagram(std::string s, std::string t) {
    // Check if the lengths of the strings are equal
    if (s.length() != t.length()) {
        return false;
    }
    
    // Create a vector to count occurrences of each character
    std::vector<int> char_counts(26, 0);

    // Count characters in the first string
    for (char c : s) {
        char_counts[c - 'a']++;
    }

    // Count characters in the second string
    for (char c : t) {
        char_counts[c - 'a']--;
    }

    // Check if all counts are zero
    for (int count : char_counts) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"anagram", "nagaram"},    // true
        {"rat", "car"},            // false
        {"listen", "silent"},      // true
        {"a", "a"},                // true
        {"", ""},                  // true
        {"abc", "ab"},             // false
        {"abc", "cba"},            // true
        {"abcd", "dcba"},          // true
        {"hello", "bello"},        // false
        {"schoolmaster", "theclassroom"} // true
    };

    std::vector<bool> expected = {
        true, false, true, true, true, false, true, true, false, true
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        bool result = isAnagram(tests[i].first, tests[i].second);
        std::cout << "Test " << (i + 1) << ": \"" << tests[i].first << "\" and \"" << tests[i].second << "\" -> "
                  << (result ? "Anagrams" : "Not Anagrams")
                  << " (expected: " << (expected[i] ? "Anagrams" : "Not Anagrams") << ")\n";
    }

    return 0;
}