#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    public:
        // Function to find the distance of nearest 1 in the grid for each cell
        vector<vector<int>> nearest(vector<vector<int>> grid) {
            int noOfRows = grid.size();
            int noOfCols = grid[0].size();

            // visited and distance matrix
            vector<vector<int>> visited(noOfRows, vector<int>(noOfCols, 0));
            vector<vector<int>> distance(noOfRows, vector<int>(noOfCols, 0));

            // {{row,col}, steps}
            queue<pair<pair<int,int>, int>> q;

            /**
             * Traversing the grid to find all 1s & push them to
             * the queue. We need to run BFS on these 1s to find
             * the min distance of 1s from all others cells
             */
            for (int row = 0; row < noOfRows; row++) {
                for (int col = 0; col < noOfCols; col++) {
                    // start BFS if cell contains 1
                    if (grid[row][col] == 1) {
                        // adding <coordinates, steps>
                        q.push({{row,col}, 0}); 
                        visited[row][col] = 1; 
                    } else {
                        // mark unvisited 
                        visited[row][col] = 0; 
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
                    int newRow = row + moveRow[i]; 
                    int newCol = col + moveCol[i]; 
                    // check for valid unvisited cell
                    if ((newRow >= 0 && newRow < noOfRows) &&
                        (newCol >= 0 && newCol < noOfCols) &&
                        (visited[newRow][newCol] == 0)) {
                        visited[newRow][newCol] = 1; 
                        // we increment current steps by 1
                        q.push({{newRow, newCol}, steps + 1});  
                    }
                }
            }

            // return distance matrix
            return distance; 
	    }
};

int main(){
    vector<vector<int>> grid    {
                                    { 0,1,1,0 },
                                    { 1,1,0,0 },
                                    { 0,0,1,1 }
                                };

    Solution obj;
    vector<vector<int>> ans = obj.nearest(grid);

    // print the ans matrix
    for (auto vector : ans) {
        for (auto element : vector) {
            cout << element << " ";
        }
        cout << "\n";
    }

    return 0;
}