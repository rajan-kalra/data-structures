#include<iostream>
#include<vector>
using namespace std;

int uniquePathsRecursiveHelper(vector<vector<int>>& A, int rows, int cols, int i, int j) {
    // CASE: when either of the boundary is crossed due
    // to movement toward down or right
    if (i >= rows || j >= cols)
        return 0;

    // CASE: when destination is reached i.e grid[m-1][n-1]
    // starting from grid[0][0]. Keeping this
    // condition as 2nd as this will fail in most cases
    // if kept on top
    if (i == rows-1 && j == cols-1)
        return 1;

    // number of paths if we move 1 step down
    int down = uniquePathsRecursiveHelper (A, rows, cols, i+1, j);

    // number of paths if we move 1 step right
    int right = uniquePathsRecursiveHelper (A, rows, cols, i, j+1);

    // sum up all the paths 
    return down + right;
}

int uniquePathsRecursive(vector<vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    return uniquePathsRecursiveHelper(A, rows, cols, 0, 0);
}

int uniquePathsMemoizationHelper(vector<vector<int>>& A, int rows, int cols, int i, int j, vector<vector<int>> &learn) {
    // CASE: when either of the boundary is crossed due
    // to movement toward down or right
    if (i >= rows || j >= cols)
        return 0;

    // CASE: when destination is reached i.e grid[m-1][n-1]
    // starting from grid[0][0]. Keeping this
    // condition as 2nd as this will fail in most cases
    // if kept on top
    if (i == rows-1 && j == cols-1)
        return 1;

    if (learn[i][j] != 0)
        return learn[i][j];

    // number of paths if we move 1 step down
    int down = uniquePathsRecursiveHelper (A, rows, cols, i+1, j);

    // number of paths if we move 1 step right
    int right = uniquePathsRecursiveHelper (A, rows, cols, i, j+1);

    // sum up all the paths 
    return learn[i][j] = down + right;
}

int uniquePathsMemoization(vector<vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> learn(rows, vector<int>(cols, 0));
    return uniquePathsMemoizationHelper(A, rows, cols, 0, 0, learn);
}

int main() {
    vector<vector<int>> A = { 
                                { 0, 0, 0 },
                                { 0, 0, 0 },
                                { 0, 0, 0 }
                            };

    cout << "Unique paths using recursion: " << uniquePathsRecursive(A) << endl;
    cout << "Unique paths using memoization: " << uniquePathsMemoization(A) << endl;
}
