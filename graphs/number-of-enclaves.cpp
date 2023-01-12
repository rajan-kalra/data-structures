#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &inputGrid) {
      queue<pair<int,int>> q; 
      int noOfRows = inputGrid.size(); 
      int noOfCols = inputGrid[0].size();
      vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));

      // traverse boundary elements
      for (int i = 0; i < noOfRows; i++) {
        for (int j = 0; j < noOfCols; j++) {
          // first row, first col, last row, last col 
          if (i == 0 || j == 0 || i == noOfRows - 1 || j == noOfCols - 1) {
            // if it is a land then store it in queue
            if (inputGrid[i][j] == 1) {
              // insert coordinates
              q.push({i, j}); 
              visited[i][j] = 1; 
            }
          }
        }
      }
        
      int moveRow[] = {-1, 0, +1, 0};
      int moveCol[] = {0, +1, +0, -1}; 
        
      while(q.empty() == false) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // traverses all 4 directions
        for(int i = 0; i < 4; i++) {
          int nrow = row + moveRow[i];
          int ncol = col + moveCol[i]; 
          // check for valid coordinates and for land cell
          if((nrow >=0 && nrow < noOfRows) && (ncol >=0 && ncol < noOfCols) && (visited[nrow][ncol] == 0 && inputGrid[nrow][ncol] == 1)) {
            q.push({nrow, ncol});
            visited[nrow][ncol] = 1; 
          }
        }
          
      }
        
      int count = 0;
      for (int i = 0; i < noOfRows; i++) {
        for (int j = 0; j < noOfCols; j++) {
          // check for unvisited land cell
          if (inputGrid[i][j] == 1 && visited[i][j] == 0) {
              count++;
          }
        }
      }

      return count; 
    }
};

int main() {
  vector<vector<int>> inputGrid  {
                              {0, 0, 0, 0},
                              {1, 0, 1, 0},
                              {0, 1, 1, 0},
                              {0, 0, 0, 0}
                            };

  Solution obj;
  cout << obj.numberOfEnclaves(inputGrid) << endl;
}