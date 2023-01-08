#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
 
// Below arrays detail all eight possible movements from a cell
// (up, up-right, right, down-right, down, down-left, left, up-left)
int moveRow[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
int moveCol[] = {  0,  1, 1, 1, 0, -1, -1, -1 };
 
/**
 * Function to check if it is safe to go to position (x, y) from
 * the current position. The function returns false if (x, y) is
 * not valid matrix coordinates or (x, y) represents water or
 * position (x, y) is already processed
 **/
bool isSafe(vector<vector<int>> const &mat, int nrow, int ncol, vector<vector<bool>> const &processed) {
  // check new row is a valid index && check new col is a valid index && new index represents land && new index is not visited before
  return (nrow >= 0 && nrow < mat.size()) && (ncol >= 0 && ncol < mat[0].size()) &&
        mat[nrow][ncol] == 1 && processed[nrow][ncol] == false;
}
 
void BFS(vector<vector<int>> const &mat, vector<vector<bool>> &processed, int row, int col) {
  // create an empty queue and enqueue current
  // source node's indices. We need to store these
  // indices as here we need to figure out which is
  // the current index we are processing as input is
  // given in the form of land & water in a cell
  queue<pair<int, int>> q;
  q.push(make_pair(row, col));

  // mark current source node as processed
  processed[row][col] = true;

  // loop till queue is empty
  while (!q.empty()) {
    // dequeue front node and process it
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    // check for all eight possible movements from the current cell
    // and enqueue each valid movement
    for (int k = 0; k < 8; k++) {
      /**
       * skip the cell if:
       * 1. location is invalid
       * 2. already processed
       * 3. consists of water
       */
      if (isSafe(mat, x + moveRow[k], y + moveCol[k], processed)) {
        // mark this cell movement as processed and enqueue it
        processed[x + moveRow[k]][y + moveCol[k]] = 1;
        q.push(make_pair(x + moveRow[k], y + moveCol[k]));
      }
    }
  }
}
 
int countIslands(vector<vector<int>> const &mat) {

  // `rows × cols` matrix
  int rows = mat.size();
  int cols = mat[0].size();

  // stores if a cell is processed or not
  vector<vector<bool>> processed(rows, vector<bool>(cols));

  int no_of_islands = 0;
  // We iterate through the complete matrix & apply BFS on
  // each cell as there can be multiple connected components
  // in the given matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      /**
       * to start BFS we check 2 conditions:
       * 1. current cell should be land
       * 2. we may have not visited this cell of land
       */
      if (mat[i][j] == 1 && processed[i][j] == 0) {
        BFS(mat, processed, i, j);
        no_of_islands++;
      }
    }
  }

  return no_of_islands;
}
 
int main()
{
  vector<vector<int>> mat =
  {
      { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
      { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
      { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
      { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
      { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
      { 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
      { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
      { 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
      { 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
  };
 
  cout << "The total number of islands is " << countIslands(mat) << endl;
 
  return 0;
}