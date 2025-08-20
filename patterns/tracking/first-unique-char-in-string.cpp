#include <iostream>
#include <string>
#include <vector>

int firstUniqChar(std::string s) {
    // Frequency array for lowercase English letters
    std::vector<int> charCounts(26, 0);

    // First pass: Count character frequencies
    for (char c : s) {
        charCounts[c - 'a']++;
    }

    // Second pass: Find the first unique character
    for (int i = 0; i < s.length(); ++i) {
        if (charCounts[s[i] - 'a'] == 1) {
            return i;
        }
    }

    // No unique character found
    return -1;
}

int main() {
    std::string testString = "leetcode";
    int index = firstUniqChar(testString);
    if (index != -1) {
        std::cout << "The first unique character is '" << testString[index] << "' at index " << index << ".\n";
    } else {
        std::cout << "No unique character found.\n";
    }

    return 0;
}