#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
class Solution {
  public:
    //Function to find minimum time required to rot all oranges
    int orangesRotting(vector<vector<int>> &grid) {
      // figure out the grid size
      int noOfRows = grid.size();
      int noOfCols = grid[0].size();

      // store {{row, column}, time}
      queue<pair<pair<int,int>, int>> q;
      int visited[noOfRows][noOfCols];
      int countOfFreshOranges = 0;
 
      /**
       * Iterating through the entire grid to find out count of
       * fresh oranges & creating the visited matrix
       **/
      for (int i = 0; i < noOfRows; i++) {
        for (int j = 0; j < noOfCols; j++) {
          // if cell contains rotten orange
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            // mark as visited (rotten) in visited array
            visited[i][j] = 2;
          // if not rotten
          } else {
            visited[i][j] = 0;
          }

          // count fresh oranges
          if (grid[i][j] == 1) {
            countOfFreshOranges++;
          }
        }
      }
 
      int tm = 0;
      // delta movement row and column
      int moveRow[] = {-1, 0, +1, 0};
      int moveCol[] = {0, 1, 0, -1};
      int count = 0;
 
      // bfs traversal (until the queue becomes empty)
      while (q.empty() == false) {
        int currRow = q.front().first.first;
        int currCol = q.front().first.second;
        int unitTime = q.front().second;
        tm = max(tm, unitTime);
        q.pop();

        // exactly 4 neighbours 
        for (int i = 0; i < 4; i++) {
          // neighbouring row and column
          int newRow = currRow + moveRow[i];
          int newCol = currCol + moveCol[i];
          /**
           * conditions to be checked to apply dfs on new cell:
           * 1. New row is valid
           * 2. New col is valid
           * 3. New cell is not visited in visited matrix
           * 4. New cell has a fresh orange
           */
          if ((newRow >= 0 && newRow < noOfRows) && (newCol >= 0 && newCol < noOfCols) && (visited[newRow][newCol] == 0) && (grid[newRow][newCol] == 1)) {
            // push in queue with timer increased
            q.push({{newRow, newCol}, unitTime + 1}); 
            // mark as rotten
            visited[newRow][newCol] = 2;
            count++;
          }
        }
      }
 
      // if all oranges are not rotten
      if (count != countOfFreshOranges)
        return -1;
  
      return tm;
    }
};
 
int main() {
  vector<vector<int>> grid	{
                              {0, 1, 2},
                              {0, 1, 2},
                              {2, 1, 1}
                            };

  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";
  return 0;
}