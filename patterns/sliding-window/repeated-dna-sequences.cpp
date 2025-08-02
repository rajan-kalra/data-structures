#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
  std::unordered_set<std::string> seen;
  std::unordered_set<std::string> repeated;

  if (s.length() < 10) {
      // return an empty vector
      return std::vector<std::string>();
  }

  for (int i = 0; i <= s.length() - 10; ++i) {
      std::string current_sequence = s.substr(i, 10);
      if (seen.count(current_sequence)) { // If already seen, it's a repeated sequence
          repeated.insert(current_sequence);
      }
      seen.insert(current_sequence); // Mark as seen
  }

  std::vector<std::string> result(repeated.begin(), repeated.end());
  return result;
}

int main() {
  std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  std::vector<std::string> result = findRepeatedDnaSequences(s);
  std::cout << "Repeated DNA sequences are: ";
  for (const auto& seq : result) {
      std::cout << seq << " ";
  }
  std::cout << std::endl;
  return 0;
}