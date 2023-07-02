#include<iostream>
#include<vector>
using namespace std;

int getUniquePathsWithObstaclesMemoizedUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j, vector<vector<int>> &learn) {
    // out of boundary edge case
     if (i >= rows || j >= cols)
        return 0;
    
    // obstacle edge case
    if (mat[i][j] == 1)
        return 0;

    // destination edge case
    if ((i == rows-1) && (j == cols-1)) {
        // beautiful edge case
        if (mat[i][j] == 1)
			return 0;
        return 1;
    }

    if (learn[i][j] != -1)
        return learn[i][j];

    int down = getUniquePathsWithObstaclesMemoizedUtil (mat, rows, cols, i+1, j, learn);
    int right = getUniquePathsWithObstaclesMemoizedUtil (mat, rows, cols, i, j+1, learn);
    
    return learn[i][j] = down + right;
}

int getUniquePathsWithObstaclesMemoized (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i, j as 0, 0 to always start from from (0,0) cell
    int i = 0, j = 0;

    vector<vector<int>> learn(rows, vector<int>(cols, -1));
    return getUniquePathsWithObstaclesMemoizedUtil(mat, rows, cols, i, j, learn);
}

int getUniquePathsWithObstaclesRecursiveUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j) {
    // out of boundary edge case
    if (i >= rows || j >= cols)
        return 0;
    
    // obstacle edge case
    if (mat[i][j] == 1)
        return 0;

    // destination edge case
    if ((i == rows-1) && (j == cols-1)) {
        // beautiful edge case
        if (mat[i][j] == 1)
			return 0;
        return 1;
    }

    int down = getUniquePathsWithObstaclesRecursiveUtil (mat, rows, cols, i+1, j);
    int right = getUniquePathsWithObstaclesRecursiveUtil (mat, rows, cols, i, j+1);
    
    return down + right;

}

int getUniquePathsWithObstaclesRecursive (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i, j as 0, 0 to always start from from (0,0) cell
    int i = 0, j = 0;

    return getUniquePathsWithObstaclesRecursiveUtil(mat, rows, cols, i, j);
}

int getUniquePathsWithObstacles (vector<vector<int>> &mat) {
    // return getUniquePathsWithObstaclesRecursive(mat);
    return getUniquePathsWithObstaclesMemoized(mat);
}

int main() {
    vector<vector<int>> mat =   {
                                    { 0, 0, 0 },
                                    { 0, 1, 0 },
                                    { 0, 0, 0 }
                                };

    cout << "Number of unique path when obstacles are present: " << getUniquePathsWithObstacles(mat) << endl;
}
