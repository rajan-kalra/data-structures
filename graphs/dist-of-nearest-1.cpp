#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
  //Function to find the distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> grid) {
    int noOfRows = grid.size();
    int noOfCols = grid[0].size();

    // visited and distance matrix
    vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));
    vector<vector<int>> distance(noOfRows, vector<int>(noOfCols, 0));

    // <coordinates, steps>
    queue<pair<pair<int,int>, int>> q;

    // traverse the matrix
    for (int i = 0; i < noOfRows; i++) {
      for (int j = 0; j < noOfCols; j++) {
        // start BFS if cell contains 1
        if (grid[i][j] == 1) {
          // adding <coordinates, steps>
          q.push({{i,j}, 0}); 
          visited[i][j] = 1; 
        } else {
          // mark unvisited 
          visited[i][j] = 0; 
        }
      }
    }

    int moveRow[] = {-1, 0, +1, 0}; 
    int moveCol[] = {0, +1, 0, -1}; 
    
    // traverse till queue becomes empty
    while (q.empty() == false) {
      // get coordinates
      int row = q.front().first.first; 
      int col = q.front().first.second;

      // get number of steps
      int steps = q.front().second; 
      q.pop();

      distance[row][col] = steps; 
      // for all 4 neighbours
      for (int i = 0; i < 4; i++) {
          int nrow = row + moveRow[i]; 
          int ncol = col + moveCol[i]; 
          // check for valid unvisited cell
          if ((nrow >= 0 && nrow < noOfRows) && (ncol >= 0 && ncol < noOfCols) && (visited[nrow][ncol] == 0)) {
              visited[nrow][ncol] = 1; 
              // we increment current steps by 1
              q.push({{nrow, ncol}, steps + 1});  
          }
      }
    }

    // return distance matrix
    return distance; 
	}
};

int main(){
  vector<vector<int>> grid  {
                              {0,1,1,0},
                              {1,1,0,0},
                              {0,0,1,1}
                            };

  Solution obj;
  vector<vector<int>> ans = obj.nearest(grid);
  // print the ans matrix
  for (auto i : ans) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}