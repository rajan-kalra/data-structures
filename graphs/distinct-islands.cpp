#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
    private:
        void dfs(int currentRow, int currentCol, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int,int>> &coordinates_vector, int baseRow, int baseCol) {
            // mark the cell as visited
            visited[currentRow][currentCol] = 1;

            // coordinates - base coordinates
            coordinates_vector.push_back({ currentRow - baseRow, currentCol - baseCol });
            int n = grid.size();
            int m = grid[0].size();

            // delta row and delta column
            int moveRow[] = {-1, 0, +1, 0}; 
            int moveCol[] = {0, -1, 0, +1}; 

            // traverse all 4 neighbours
            for (int i = 0; i < 4; i++) {
                int newRow = currentRow + moveRow[i];
                int newCol = currentCol + moveCol[i];

                // check for valid unvisited land neighbour coordinates 
                if ((newRow >= 0 && newRow < n) &&
                    (newCol >= 0 && newCol < m) &&
                    (visited[newRow][newCol] == false) &&
                    (grid[newRow][newCol] == 1)) {
                    dfs(newRow, newCol, visited, grid, coordinates_vector, baseRow, baseCol);
                }
            }
        }

    public:
        int countDistinctIslands(vector<vector<int>> &grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector<int>> visited(rows, vector<int>(cols, 0));
            set<vector<pair<int,int>>> shapes_set;

            // traverse the grid
            for (int currentRow = 0; currentRow < rows; currentRow++) {
                for (int currentCol = 0; currentCol < cols; currentCol++) {
                    // if not visited and is a land cell
                    if ((visited[currentRow][currentCol] == false) && grid[currentRow][currentCol] == 1) {
                        vector<pair<int,int>> coordinates_vector;
                        dfs(currentRow, currentCol, visited, grid, coordinates_vector, currentRow, currentCol);
                        // store in set
                        shapes_set.insert(coordinates_vector);
                    }
                }
            }

            return shapes_set.size();
        }
};

int main() {
    vector<vector<int>> grid    {
                                    {1, 1, 0, 1, 1},
                                    {1, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 1},
                                    {1, 1, 0, 1, 1}
                                };

    Solution obj;
    cout << "Number of distinct islands: " << obj.countDistinctIslands(grid) << endl;
}