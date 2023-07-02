#include<iostream>
#include<vector>
using namespace std;

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumVariableStartPointMemoizedUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j, vector<vector<int>> &learn) {
    // Out of boundary base case. In this problem, we can go out of boundary
    // only for columns. This is bcoz for rows we return as soon as we touch row
    // which is last row & for cols we need to handle the case for indexes [0][0]
    // & [0][cols-1], for these 2 indexes when we do leftDiagonal & rightDiagonal
    // respectively, we end up stepping out of the boundary
    if (j < 0 || j >= cols)
        return 1e9;
    
    // Destination reached base case. For this problem, destination can be any
    // index in first row
    if (i == rows-1)
        return mat[i][j];

    if (learn[i][j] != -1)
        return learn[i][j];

    int down = mat[i][j] + minPathSumVariableStartPointMemoizedUtil (mat, rows, cols, i+1, j, learn);
    int downLeft = mat[i][j] + minPathSumVariableStartPointMemoizedUtil (mat, rows, cols, i+1, j-1, learn);
    int downRight = mat[i][j] + minPathSumVariableStartPointMemoizedUtil (mat, rows, cols, i+1, j+1, learn);
    
    return learn[i][j] = min(down, min(downLeft, downRight));
}

int minPathSumVariableStartPointMemoized (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i as 0 to always start from 0th row
    int i = 0;

    // extremely important step to init currentMin & min_sum with INT_MAX
    int currentMin = INT_MAX, min_sum = INT_MAX;

    vector<vector<int>> learn(rows, vector<int>(cols, -1));
    for (int j = 0; j < cols; j++) {
        currentMin = minPathSumVariableStartPointMemoizedUtil(mat, rows, cols, i, j, learn);
        min_sum = min(currentMin, min_sum);
    }

    return min_sum;
}

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumVariableStartPointRecursiveUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j) {
    // Out of boundary base case. In this problem, we can go out of boundary
    // only for columns. This is bcoz for rows we return as soon as we touch row
    // which is last row & for cols we need to handle the case for indexes [0][0]
    // & [0][cols-1], for these 2 indexes when we do leftDiagonal & rightDiagonal
    // respectively, we end up stepping out of the boundary
    if (j < 0 || j >= cols)
        return 1e9;
    
    // Destination reached base case. For this problem, destination can be any
    // index in first row
    if (i == rows-1)
        return mat[i][j];

    int down = mat[i][j] + minPathSumVariableStartPointRecursiveUtil (mat, rows, cols, i+1, j);
    int downLeft = mat[i][j] + minPathSumVariableStartPointRecursiveUtil (mat, rows, cols, i+1, j-1);
    int downRight = mat[i][j] + minPathSumVariableStartPointRecursiveUtil (mat, rows, cols, i+1, j+1);
    
    return min(down, min(downLeft, downRight));
}

int minPathSumVariableStartPointRecursive (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i as 0 to start always from 0th row
    int i = 0;

    // extremely important step to init currentMin & min_sum with INT_MAX
    int currentMin = INT_MAX, min_sum = INT_MAX;

    for (int j = 0; j < cols; j++) {
        currentMin = minPathSumVariableStartPointRecursiveUtil(mat, rows, cols, i, j);
        min_sum = min(currentMin, min_sum);
    }

    return min_sum;
}

int minPathSumVariableStartPoint (vector<vector<int>> &mat) {
    return minPathSumVariableStartPointRecursive(mat);
    // return minPathSumVariableStartPointMemoized(mat);
}

int main() {
    vector<vector<int>> mat =   {
                                    { 2, 1, 3 },
                                    { 6, 5, 4 },
                                    { 7, 8, 9 }
                                };

    cout << "Minimum path sum with variable starting points: " << minPathSumVariableStartPoint(mat) << endl;
}
