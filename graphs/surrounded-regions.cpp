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
                if ((nrow >= 0 && nrow < noOfRows) &&
                    (ncol >= 0 && ncol < noOfCols) &&
                    (!visited[nrow][ncol] && mat[nrow][ncol] == 'O')) {
                    dfs(nrow, ncol, visited, mat, moveRow, moveCol);
                }
            }
        }

    public:
        vector<vector<char>> fill(int noOfRows, int noOfCols, vector<vector<char>> inputGrid) {
            int moveRow[] = { -1, 0, +1,  0 };
            int moveCol[] = {  0, 1,  0, -1 };

            vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));
        
            /**
             * Traversing first and last row
             * We apply dfs on every 0 found on boundary
             */ 
            for (int col = 0; col < noOfCols; col++) {
                // first row 
                if (inputGrid[0][col] == 'O' && visited[0][col] == 0) {
                    dfs(0, col, visited, inputGrid, moveRow, moveCol); 
                }
                
                // last row 
                if(inputGrid[noOfRows-1][col] == 'O' && visited[noOfRows-1][col] == 0) {
                    dfs(noOfRows-1, col, visited, inputGrid, moveRow, moveCol); 
                }
            }
            
            /**
             * Traversing first and last column
             * We apply dfs on every 0 found on boundary
             */ 
            for (int row = 0; row < noOfRows; row++) {
                // first column 
                if (inputGrid[row][0] == 'O' && visited[row][0] == 0) {
                    dfs(row, 0, visited, inputGrid, moveRow, moveCol); 
                }
                
                // last column
                if (inputGrid[row][noOfCols-1] == 'O' && visited[row][noOfCols-1] == 0) {
                    dfs(row, noOfCols-1, visited, inputGrid, moveRow, moveCol); 
                }
            }

            /**
             * At this point if any cell in the grid is left
             * with 0, it infers that it wasn't reachable from
             * any 0 on the boundary& thus can be transformed to X
             */
            for (int i = 0; i < noOfRows; i++) {
                for (int j = 0; j < noOfCols; j++) {
                    if (visited[i][j] == 0 && inputGrid[i][j] == 'O') 
                        inputGrid[i][j] = 'X'; 
                }
            }
            
            return inputGrid; 
        }
};

int main() {
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

    for (int row = 0; row < noOfRows; row++) {
        for (int col = 0; col < noOfCols; col++) {
            cout << ans[row][col] << " ";
        }
        cout<<"\n";
    }

    return 0;
}