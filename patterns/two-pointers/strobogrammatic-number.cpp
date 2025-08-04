#include <iostream>
#include <unordered_set>
#include <vector>

bool isStrobogrammatic(std::string num) {
  std::unordered_map<char, char> strobogrammatic_map = {
      {'0', '0'},
      {'1', '1'},
      {'6', '9'},
      {'8', '8'},
      {'9', '6'}
  };

  int left = 0;
  int right = num.length() - 1;

  while (left <= right) {
    char left_char = num[left];
    char right_char = num[right];

    // Check if the left character is a valid strobogrammatic digit
    if (strobogrammatic_map.find(left_char) == strobogrammatic_map.end()) {
        return false;
    }

    // Check if the right character is the correct rotated counterpart
    if (strobogrammatic_map[left_char] != right_char) {
        return false;
    }

    // Move pointers inward
    left++;
    right--;
  }

  return true;
}

int main() {
  std::string num = "69";
  if (isStrobogrammatic(num)) {
      std::cout << num << " is strobogrammatic." << std::endl;
  } else {
      std::cout << num << " is not strobogrammatic." << std::endl;
  }
  return 0;
}