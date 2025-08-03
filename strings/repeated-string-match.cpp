#include <iostream>
#include <vector>
#include <string>
#include <unordered_set> // For efficient storage of unique emails

class Solution {
public:
  int repeatedStringMatch(std::string a, std::string b) {
    std::string temp_a = a;
    int count = 1;

    // Keep repeating 'a' until temp_a is at least as long as 'b'
    // or slightly longer to account for potential wrapping.
    // We need temp_a to be long enough to contain b fully.
    // A safe upper bound for the length of temp_a to check is
    // length_b + length_a.
    // For example, if a="ab" and b="bca", length of b is 3, length of a is 2.
    // b needs 2 'a's (ab + ab). temp_a becomes "abab".
    // b "bca" starts with 'b' from first 'a' and ends with 'a' from second 'a'.
    // So, if b can be a substring, it must be found within a string formed by
    // at most ceil(len_b / len_a) + 2 repetitions of 'a'.
    while (temp_a.length() < b.length()) {
        temp_a += a;
        count++;
    }

    // Check if b is a substring in the current temp_a
    if (temp_a.find(b) != std::string::npos) {
        return count;
    }

    // If not found, append 'a' one more time.
    // This handles cases where 'b' spans across the boundary of the current `temp_a` and the next `a`.
    // E.g., a = "abcd", b = "cdabcdab".
    // 1st iter: temp_a = "abcd", count = 1. b not found.
    // 2nd iter: temp_a = "abcdabcd", count = 2. b not found.
    // 3rd iter: temp_a = "abcdabcdabcd", count = 3. b found!
    // In the initial loop, temp_a.length() could be only slightly larger than b.length().
    // If b starts at the end of temp_a and wraps to the beginning of the next 'a',
    // we need to append 'a' one more time.
    temp_a += a;
    count++;

    if (temp_a.find(b) != std::string::npos) {
        return count;
    }

    // If 'b' is still not found after two checks, it means it can't be formed.
    return -1;
  }
};

// Example Usage (for testing locally)
int main() {
  Solution sol;
  std::string a = "abcd";
  std::string b = "cdabcdab";
  int result = sol.repeatedStringMatch(a, b);
  std::cout << "Result: " << result << std::endl; // Expected output: 3

  return 0;
}