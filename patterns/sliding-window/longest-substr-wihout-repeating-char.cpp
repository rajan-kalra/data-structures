#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    // map for storing the last seen index of each character
    std::unordered_map<char, int> charIndexMap;
    int left = 0;
    int maxLength = 0;
    int currentWindowLen = 0;

    for (int right = 0; right < s.length(); ++right) {
         char currentChar = s[right];
        
        // Check if the current character is already in the map
        if (charIndexMap.count(currentChar) && charIndexMap[currentChar] >= left) {
            // If it is, and its last seen index is within the current window,
            // move the left pointer to the position after the last occurrence.
            // Here we get the last seen index of the current character & move the left pointer to that index + 1
            left = charIndexMap[currentChar] + 1;
        }
        
        // Update the character's index in the map
        charIndexMap[currentChar] = right;

        // Update the current window length
        currentWindowLen = right - left + 1;

        // Calculate the length of the current window and update max length
        maxLength = std::max(maxLength, currentWindowLen);
    }
    
    return maxLength;
}

int main() {
    // Test 1: Basic example
    std::string s1 = "abcabcbb";
    int result1 = lengthOfLongestSubstring(s1);
    std::cout << "Test 1: " << result1 << " (expected: 3)" << std::endl;
    // "abc" is the longest substring without repeating characters

    // Test 2: All same characters
    std::string s2 = "bbbbb";
    int result2 = lengthOfLongestSubstring(s2);
    std::cout << "Test 2: " << result2 << " (expected: 1)" << std::endl;
    // Only one unique character

    // Test 3: All unique characters
    std::string s3 = "pwwkew";
    int result3 = lengthOfLongestSubstring(s3);
    std::cout << "Test 3: " << result3 << " (expected: 3)" << std::endl;
    // "wke" is the longest substring

    // Test 4: Empty string
    std::string s4 = "";
    int result4 = lengthOfLongestSubstring(s4);
    std::cout << "Test 4: " << result4 << " (expected: 0)" << std::endl;

    // Test 5: Single character
    std::string s5 = "a";
    int result5 = lengthOfLongestSubstring(s5);
    std::cout << "Test 5: " << result5 << " (expected: 1)" << std::endl;

    // Test 6: Two characters alternating
    std::string s6 = "abab";
    int result6 = lengthOfLongestSubstring(s6);
    std::cout << "Test 6: " << result6 << " (expected: 2)" << std::endl;
    // "ab" is the longest

    // Test 7: Entire string is unique
    std::string s7 = "abcdef";
    int result7 = lengthOfLongestSubstring(s7);
    std::cout << "Test 7: " << result7 << " (expected: 6)" << std::endl;

    // Test 8: Complex pattern
    std::string s8 = "dvdf";
    int result8 = lengthOfLongestSubstring(s8);
    std::cout << "Test 8: " << result8 << " (expected: 3)" << std::endl;
    // "vdf" is the longest

    // Test 9: Numbers and special characters
    std::string s9 = "abcabcbb";
    int result9 = lengthOfLongestSubstring(s9);
    std::cout << "Test 9: " << result9 << " (expected: 3)" << std::endl;
    // "abc" is the longest substring without repeating characters

    return 0;
}