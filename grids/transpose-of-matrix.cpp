#include<iostream>
#include<vector>
using namespace std;

void transpose (vector<vector<int> > &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < cols; i++)
        for (int j = 0; j <= i; j++)
            swap(mat[i][j], mat[j][i]);
}

void printMatrix (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
        
}

int main() {
    vector<vector<int>> mat = { 
                                { 11, 12, 13, 14 },
                                { 21, 22, 23, 24 },
                                { 31, 32, 33, 34 },
                                { 41, 42, 43, 44 }
                            };

    cout << "Matrix before transpose: " << endl;
    printMatrix(mat);
    transpose(mat);
    cout << "Matrix after transpose: " << endl;
    printMatrix(mat);
}
