#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int characterReplacement(std::string s, int k) {
    std::vector<int> freq(26, 0);
    int max_freq = 0;
    int max_length = 0;
    int left = 0;

    for (int right = 0; right < s.length(); ++right) {
        // Expand the window
        freq[s[right] - 'A']++;
        max_freq = std::max(max_freq, freq[s[right] - 'A']);

        // Check if the window is invalid
        int window_length = right - left + 1;
        if (window_length - max_freq > k) {
            // Shrink the window
            freq[s[left] - 'A']--;
            left++;
        }

        // Update max_length
        max_length = std::max(max_length, right - left + 1);
    }
    
    return max_length;
}

int main() {
    // Test 1: Basic example
    std::string s1 = "AABABBA";
    int k1 = 1;
    int result1 = characterReplacement(s1, k1);
    std::cout << "Test 1: " << result1 << " (expected: 4)" << std::endl;
    // Can replace one B to get "AAAA" (substring "AABA" -> "AAAA")

    // Test 2: All same characters
    std::string s2 = "ABAB";
    int k2 = 2;
    int result2 = characterReplacement(s2, k2);
    std::cout << "Test 2: " << result2 << " (expected: 4)" << std::endl;
    // Can replace 2 characters to get all A's or all B's

    // Test 3: No replacements needed
    std::string s3 = "AAAA";
    int k3 = 0;
    int result3 = characterReplacement(s3, k3);
    std::cout << "Test 3: " << result3 << " (expected: 4)" << std::endl;
    // Already all same characters

    // Test 4: Single character
    std::string s4 = "A";
    int k4 = 1;
    int result4 = characterReplacement(s4, k4);
    std::cout << "Test 4: " << result4 << " (expected: 1)" << std::endl;

    // Test 5: Large k value
    std::string s5 = "ABCDEF";
    int k5 = 5;
    int result5 = characterReplacement(s5, k5);
    std::cout << "Test 5: " << result5 << " (expected: 6)" << std::endl;
    // Can replace 5 characters to make all same

    // Test 6: k = 0, mixed characters
    std::string s6 = "ABABAB";
    int k6 = 0;
    int result6 = characterReplacement(s6, k6);
    std::cout << "Test 6: " << result6 << " (expected: 1)" << std::endl;
    // No replacements allowed, longest is single character

    // Test 7: Longer string
    std::string s7 = "AABABBA";
    int k7 = 2;
    int result7 = characterReplacement(s7, k7);
    std::cout << "Test 7: " << result7 << " (expected: 5)" << std::endl;
    // Can replace 2 B's to get "AAAAA"

    return 0;
}