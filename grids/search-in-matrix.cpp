#include <iostream>
#include <vector>

using namespace std;

int search(vector<vector<int> > &mat, int n, int x) {
    int row = 0, col = n-1;
    while (row < n && col >=0) {
        if (mat[row][col] == x)
            return 1;
        else if (x < mat[row][col])
            col--;
        else
            row++;
    }

    return 0;
}

// Driver code
int main() {
    vector<vector<int> > mat
    {
        { 10, 20, 30, 40 },
        { 15, 25, 35, 45 },
        { 27, 29, 37, 48 },
        { 32, 33, 39, 50 }
    };

    int rows = mat.size();
    int cols = mat[0].size();

    search(mat, 4, 28) == 1 ? cout << "Element is present!" : cout << "Element is not present!";
    return 0;
}
