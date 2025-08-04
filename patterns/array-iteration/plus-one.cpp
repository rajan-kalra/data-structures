#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
  int n = digits.size();

  // Iterate from the last digit to the first
  for (int i = n - 1; i >= 0; --i) {
      // Case 1: The current digit is not a 9
      if (digits[i] < 9) {
          digits[i]++;
          return digits; // No carry-over, so we can return immediately
      }
      
      // Case 2: The current digit is a 9
      // Set it to 0 and the loop will continue to the next digit to handle the carry
      digits[i] = 0;
  }

  // This part is only reached if all digits were 9s (e.g., [9,9,9])
  // In this case, we need to add a new leading digit '1'.
  
  // We can either insert '1' at the beginning of the existing vector
  digits.insert(digits.begin(), 1);

  return digits;
}

int main() {
  std::vector<int> digits = {1, 2, 3};
  std::vector<int> result = plusOne(digits);
  std::cout << "Resulting digits are: ";
  for (int d : result) {
      std::cout << d << " ";
  }
  std::cout << std::endl;
  return 0;
}