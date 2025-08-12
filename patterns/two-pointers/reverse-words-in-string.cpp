#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());

        int n = s.length();
        int left = 0;
        int right = 0;
        int i = 0;

        // Step 2: Reverse each word and clean up spaces
        while (i < n) {
            // Find the start of the next word
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i == n) {
                break;
            }

            // Find the end of the current word
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }

            // Copy the word to its new position, adding a space if not the first word
            if (left != 0) {
                s[left++] = ' ';
            }

            // Reverse the current word and copy it
            reverse(s.begin() + i, s.begin() + j);
            for (int k = i; k < j; k++) {
                s[left++] = s[k];
            }

            i = j;
        }

        // Resize the string to the correct length
        s.resize(left);

        return s;
    }
};

int main() {
  Solution solution;
  std::string s = "the sky is blue";
  std::string reversed = solution.reverseWords(s);
  std::cout << "Reversed: '" << reversed << "'" << std::endl;
  return 0;
}