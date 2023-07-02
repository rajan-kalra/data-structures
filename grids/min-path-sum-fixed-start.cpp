#include<iostream>
#include<vector>
using namespace std;

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumFixedStartPointMemoizedUtil (vector<vector<int>> &triangle, int rows, int cols, int i, int j, vector<vector<int>> &learn) {
    // try on paper & think do we need out of boundary case in this problem
    
    // Destination reached base case. For this problem, destination can be
    // any index in last row
    if (i == rows-1)
        return triangle[i][j];

    if (learn[i][j] != -1)
        return learn[i][j];

    int down = triangle[i][j] + minPathSumFixedStartPointMemoizedUtil (triangle, rows, cols, i+1, j, learn);
    int downRight = triangle[i][j] + minPathSumFixedStartPointMemoizedUtil (triangle, rows, cols, i+1, j+1, learn);
    
    return learn[i][j] = min(down, downRight);
}

int minPathSumFixedStartPointMemoized (vector<vector<int>> &triangle) {
    int rows = triangle.size();
    int cols = triangle[0].size();
    // we init i, j as 0, 0 to always start from 0,0 index cell
    int i = 0, j = 0;

    // extremely important step of initializing the learn matrix with size as rows only
    vector<vector<int>> learn(rows, vector<int>(rows, -1));
    return minPathSumFixedStartPointMemoizedUtil(triangle, rows, cols, i, j, learn);
}

/**
 * 1e9 is 10^9 & is same as using INT_MAX.
 * 1e9 doesn't need additional header to be included.
*/
int minPathSumFixedStartPointRecursiveUtil (vector<vector<int>> &triangle, int rows, int cols, int i, int j) {
    // try on paper & think do we need out of boundary case in this problem
    
    // Destination reached base case. For this problem, destination can be any
    // index in last row
    if (i == rows-1)
        return triangle[i][j];

    int down = triangle[i][j] + minPathSumFixedStartPointRecursiveUtil (triangle, rows, cols, i+1, j);
    int downRight = triangle[i][j] + minPathSumFixedStartPointRecursiveUtil (triangle, rows, cols, i+1, j+1);
    
    return min(down, downRight);

}

int minPathSumFixedStartPointRecursive (vector<vector<int>> &triangle) {
    int rows = triangle.size();
    int cols = triangle[0].size();
    // we init i, j as 0, 0 to always start from from (0,0) cell
    int i = 0, j = 0;

    return minPathSumFixedStartPointRecursiveUtil(triangle, rows, cols, i, j);
}

int minPathSumFixedStartPoint (vector<vector<int>> &triangle) {
    // return minPathSumFixedStartPointRecursive(triangle);
    return minPathSumFixedStartPointMemoized(triangle);
}

int main() {
    vector<vector<int>> triangle =  {
                                        { 1 },
                                        { 2, 3 },
                                        { 3, 6, 7 },
                                        { 8, 9, 6, 10 }
                                    };

    cout << "Minimum path sum with fixed start point: " << minPathSumFixedStartPoint(triangle) << endl;
}
