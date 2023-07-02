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

void reverseRows (vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    for (int i = 0; i < rows; i++) {
        int low = 0;
        int high = cols - 1;
        while (low < high) {
            swap(mat[i][low], mat[i][high]);
            low++;
            high--;
        }
    }
}

void rotate90Clockwise (vector<vector<int>> &mat) {
    transpose(mat);
    reverseRows (mat);
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

    cout << "Matrix before rotation: " << endl;
    printMatrix(mat);
    rotate90Clockwise(mat);
    cout << "Matrix after rotation: " << endl;
    printMatrix(mat);
}
