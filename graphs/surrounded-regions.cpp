#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    void dfs (int row, int col, vector<vector<int>> &visited, vector<vector<char>> &mat, int moveRow[], int moveCol[]) {
      visited[row][col] = 1;
      int noOfRows = mat.size();
      int noOfCols = mat[0].size();
      
      // check for top, right, bottom, left 
      for (int i = 0; i < 4; i++) {
        int nrow = row + moveRow[i];
        int ncol = col + moveCol[i]; 
        // check for valid coordinates and unvisited Os
        if ((nrow >= 0 && nrow < noOfRows) && (ncol >= 0 && ncol < noOfCols)  && (!visited[nrow][ncol] && mat[nrow][ncol] == 'O')) {
          dfs(nrow, ncol, visited, mat, moveRow, moveCol);
        }
      }
    }

  public:
    vector<vector<char>> fill(int noOfRows, int noOfCols, vector<vector<char>> inputGrid) {
      int moveRow[] = {-1, 0, +1, 0};
      int moveCol[] = {0, 1, 0, -1};

      vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));
      
      // traverse first row and last row 
      for(int j = 0 ; j < noOfCols; j++) {
          // for boundary rows, check for unvisited Os
          // first row 
          if(inputGrid[0][j] == 'O' && visited[0][j] == 0) {
            dfs(0, j, visited, inputGrid, moveRow, moveCol); 
          }
          
          // last row 
          if(inputGrid[noOfRows-1][j] == 'O' && visited[noOfRows-1][j] == 0) {
            dfs(noOfRows-1, j, visited, inputGrid, moveRow, moveCol); 
          }
      }
        
      for (int i = 0; i < noOfRows; i++) {
          // for boundary columns, check for unvisited Os
          // first column 
          if (inputGrid[i][0] == 'O' && visited[i][0] == 0) {
            dfs(i, 0, visited, inputGrid, moveRow, moveCol); 
          }
          
          // last column
          if (inputGrid[i][noOfCols-1] == 'O' && visited[i][noOfCols-1] == 0) {
            dfs(i, noOfCols-1, visited, inputGrid, moveRow, moveCol); 
          }
      }

      // if unvisited O then convert to X
      for (int i = 0; i < noOfRows; i++) {
          for (int j = 0; j < noOfCols; j++) {
              if (visited[i][j] == 0 && inputGrid[i][j] == 'O') 
                inputGrid[i][j] = 'X'; 
          }
      }
      
      return inputGrid; 
    }
};

int main(){
  vector<vector<char>> inputGrid  {
                                    {'X', 'X', 'X', 'X'}, 
                                    {'X', 'O', 'X', 'X'}, 
                                    {'X', 'O', 'O', 'X'}, 
                                    {'X', 'O', 'X', 'X'}, 
                                    {'X', 'X', 'O', 'O'}
                                  };

  Solution ob;
  int noOfRows = inputGrid.size();
  int noOfCols = inputGrid[0].size();
  vector<vector<char>> ans = ob.fill(noOfRows, noOfCols, inputGrid);

  for (int i = 0; i < noOfRows; i++) {
    for (int j = 0; j < noOfCols; j++) {
      cout << ans[i][j] << " ";
    }
    cout<<"\n";
  }

  return 0;
}