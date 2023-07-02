#include<iostream>
#include<vector>
using namespace std;

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumMemoizedUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j, vector<vector<int>> &learn) {
    // out of boundary base case
    if (i >= rows || j >= cols)
        return 1e9;
    
    // Destination reached base case
    if ((i == rows-1) && (j == cols-1))
        return mat[i][j];

    if (learn[i][j] != -1)
        return learn[i][j];

    int down = mat[i][j] + minPathSumMemoizedUtil (mat, rows, cols, i+1, j, learn);
    int right = mat[i][j] + minPathSumMemoizedUtil (mat, rows, cols, i, j+1, learn);
    
    return learn[i][j] = min(down, right);
}

int minPathSumMemoized (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i, j as 0, 0 to always start from 0,0 index cell
    int i = 0, j = 0;

    // extremely important step of initializing the learn matrix with size as rows only
    vector<vector<int>> learn(rows, vector<int>(cols, -1));
    return minPathSumMemoizedUtil(mat, rows, cols, i, j, learn);
}

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumRecursiveUtil (vector<vector<int>> &mat, int rows, int cols, int i, int j) {
    // Out of boundary base case
    if (i >= rows || j >= cols)
        return 1e9;
    
    // Destination reached base case. For this problem, destination can be any
    // index in last row
    if ((i == rows-1) && (j == cols-1))
        return mat[i][j];

    int down = mat[i][j] + minPathSumRecursiveUtil (mat, rows, cols, i+1, j);
    int right = mat[i][j] + minPathSumRecursiveUtil (mat, rows, cols, i, j+1);
    
    return min(down, right);

}

int minPathSumRecursive (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    // we init i, j as 0, 0 to always start from from (0,0) cell
    int i = 0, j = 0;

    return minPathSumRecursiveUtil(mat, rows, cols, i, j);
}

int minPathSumFixedStartPoint (vector<vector<int>> &mat) {
    // return minPathSumRecursive(mat);
    return minPathSumMemoized(mat);
}

int main() {
    vector<vector<int>> mat =   {
                                    { 1, 3, 1 },
                                    { 1, 5, 1 },
                                    { 4, 2, 1 }
                                };

    cout << "Minimum path sum: " << minPathSumFixedStartPoint(mat) << endl;
}
