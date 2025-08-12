#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool isValidWordAbbreviation(std::string word, std::string abbr) {
        int i = 0; // Pointer for the word
        int j = 0; // Pointer for the abbreviation
        
        while (i < word.length() && j < abbr.length()) {
            if (isdigit(abbr[j])) {
                // If the character is a digit, we parse the number
                if (abbr[j] == '0') {
                    // A number cannot start with zero
                    return false;
                }
                int num = 0;
                while (j < abbr.length() && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i += num; // Advance the word pointer by the number
            } else {
                // If the character is a letter, compare it
                if (word[i] != abbr[j]) {
                    return false;
                }
                i++;
                j++;
            }
        }
        
        // Both pointers must reach the end of their respective strings
        return i == word.length() && j == abbr.length();
    }
};

int main() {
  Solution solution;
  std::string word = "internationalization";
  std::string abbr = "i12n";
  bool isValid = solution.isValidWordAbbreviation(word, abbr);
  std::cout << "Is valid abbreviation: " << (isValid ? "true" : "false") << std::endl;
  return 0;
}