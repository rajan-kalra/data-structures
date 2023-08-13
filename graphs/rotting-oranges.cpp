#include<iostream>
#include<vector>
#include<queue>
 
using namespace std;
 
class Solution {
    public:
        int rottenOranges(vector<vector<int>> &grid) {
        // find out the grid size
        int noOfRows = grid.size();
        int noOfCols = grid[0].size();

        /**
         * Queue has object {{row, column}, time}.
         * We need to know which unit time does the current
         * orange belong to. Using this corresponding time
         * for each orange we find out the next unit time
         * for each orange
         */
        queue<pair<pair<int,int>, int>> q;
        int visited[noOfRows][noOfCols];
        int countOfFreshOranges = 0;

        /**
         * Iterating through the all the cells of grid to:
         * 1. Populate the visited matrix & push all already rotten
         * oranges to queue
         * 2. Find count of fresh oranges
         **/
        for (int i = 0; i < noOfRows; i++) {
            for (int j = 0; j < noOfCols; j++) {
                /**
                 * if current cell contains rotten orange, add
                 * it to queue with starting unit time as 0 &
                 * mark it as rotten in visited array
                 */
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0}); 
                    // mark as visited (rotten) in visited array
                    visited[i][j] = 2;
                // if not rotten, mark it as non-rotten in visited array
                } else {
                    visited[i][j] = 0;
                }

                /**
                 * Count fresh oranges, to be used later to find out if
                 * any fresh orange is left by comparing with no of rotten
                 * oranges
                 */
                if (grid[i][j] == 1) {
                    countOfFreshOranges++;
                }
            }
        }
 
        int maxTime = 0;
        // delta movement row and column
        int moveRow[] = { -1, 0, +1, 0 };
        int moveCol[] = {  0, 1, 0, -1 };
        int count = 0;

        /**
         * bfs traversal (until the queue becomes empty)
         * To note, we dont need the bfs loop in this case as we
         * already have nodes / oranges to be processed in the
         * queue.
         * We essentially need to process only the oranges which
         * are rotten to start with & the oranges that will get
         * rotten in subsequent time due to already rotten oranges
         */
        while (q.empty() == false) {
            int currRowIndex = q.front().first.first;
            int currColIndex = q.front().first.second;
            int currUnitTime = q.front().second;

            maxTime = max(maxTime, currUnitTime);
            q.pop();

            // current orange can rot 4 neighbours in 4 directions
            for (int i = 0; i < 4; i++) {
                // neighbouring row and column
                int newRowIndex = currRowIndex + moveRow[i];
                int newColIndex = currColIndex + moveCol[i];

                /**
                 * Conditions to check while applying bfs on new neighboring cell:
                 * 1. New row is valid
                 * 2. New col is valid
                 * 3. New cell is not visited in visited matrix
                 * 4. New cell has a fresh orange
                 */
                if ((newRowIndex >= 0 && newRowIndex < noOfRows) &&
                    (newColIndex >= 0 && newColIndex < noOfCols) &&
                    (visited[newRowIndex][newColIndex] == 0) &&
                    (grid[newRowIndex][newColIndex] == 1)) {
                    // push in queue with timer increased
                    q.push({{newRowIndex, newColIndex}, currUnitTime + 1}); 
                    // mark as rotten
                    visited[newRowIndex][newColIndex] = 2;
                    count++;
                }
            }
        }

        // if all oranges are not rotten
        if (count != countOfFreshOranges)
            return -1;

        return maxTime;
    }
};
 
int main() {
    /**
     * 0 - empty cell
     * 1 - fresh orange
     * 2 - rotten orange
     */
    vector<vector<int>> grid    {
                                    {0, 1, 2},
                                    {0, 1, 1},
                                    {2, 1, 1}
                                };

    Solution obj;
    int ans = obj.rottenOranges(grid);
    cout << ans << "\n";
    return 0;
}