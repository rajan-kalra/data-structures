#include <iostream>
#include <string>
#include <vector>

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> result;
    // Edge case: If s is shorter than p, no anagrams are possible
    if (s.length() < p.length()) {
        return result;
    }

    std::vector<int> p_freq(26, 0);
    std::vector<int> s_window_freq(26, 0);

    // Populate frequency array for p
    for (char c : p) {
        p_freq[c - 'a']++;
    }

    int left = 0;
    int right = 0;

    while (right < s.length()) {
        // Add the character at the right of the window
        s_window_freq[s[right] - 'a']++;

        // Check if the window is the correct size
        if (right - left + 1 == p.length()) {
            // Check if frequencies match
            if (p_freq == s_window_freq) {
                result.push_back(left);
            }
            // Shrink the window from the left
            s_window_freq[s[left] - 'a']--;
            left++;
        }
        right++;
    }

    return result;
}

int main() {
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> anagramIndices = findAnagrams(s, p);

    if (!anagramIndices.empty()) {
        std::cout << "Anagrams of \"" << p << "\" found at indices: ";
        for (int index : anagramIndices) {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No anagrams found." << std::endl;
    }

    return 0;
}