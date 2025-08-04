#include <iostream>
#include <set>
#include <vector>

bool areSentencesSimilar(std::vector<std::string>& words1, std::vector<std::string>& words2, std::vector<std::vector<std::string>>& similarPairs) {
  // Step 1: Check if sentences have the same length
  if (words1.size() != words2.size()) {
      return false;
  }

  // Step 2: Store similar pairs in a set for efficient lookup
  std::set<std::pair<std::string, std::string>> similar_set;
  for (const auto& p : similarPairs) {
      similar_set.insert({p[0], p[1]});
      similar_set.insert({p[1], p[0]}); // Similarity is symmetric
  }

  // Step 3: Iterate and compare corresponding words
  for (size_t i = 0; i < words1.size(); ++i) {
      // Case 1: Words are identical
      if (words1[i] == words2[i]) {
          continue;
      }

      // Case 2: Words are similar according to the pairs list
      // Check for the pair in our set
      if (similar_set.find({words1[i], words2[i]}) == similar_set.end()) {
          // If not found, sentences are not similar
          return false;
      }
  }

  // Step 4: If we get through the whole loop, the sentences are similar
  return true;
}

int main() {
  std::vector<std::string> words1 = {"great", "acting", "skills"};
  std::vector<std::string> words2 = {"fine", "drama", "talent"};
  std::vector<std::vector<std::string>> similarPairs = {
      {"great", "fine"},
      {"acting", "drama"},
      {"skills", "talent"}
  };

  bool result = areSentencesSimilar(words1, words2, similarPairs);
  std::cout << "The sentences are " << (result ? "similar" : "not similar") << "." << std::endl;

  return 0;
}