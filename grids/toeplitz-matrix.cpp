#include <iostream>
#include <vector>
using namespace std;
 
bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
  // Get the dimensions of the matrix
  int rows = matrix.size();
  if (rows == 0) {
      return true; // An empty matrix is trivially Toeplitz
  }
  int cols = matrix[0].size();

  // Iterate through the matrix, comparing each element
  // with its bottom-right neighbor.
  // We stop one row and one column short to avoid out-of-bounds access.
  for (int r = 0; r < rows - 1; ++r) {
      for (int c = 0; c < cols - 1; ++c) {
          // Check if the current element is equal to the element
          // in the next row and next column.
          if (matrix[r][c] != matrix[r + 1][c + 1]) {
              return false;
          }
      }
  }

  // If the loops complete, all diagonal elements were the same.
  return true;
}
 
int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };

    if (isToeplitzMatrix(matrix)) {
        std::cout << "The matrix is Toeplitz." << std::endl;
    } else {
        std::cout << "The matrix is not Toeplitz." << std::endl;
    }

    return 0;
}