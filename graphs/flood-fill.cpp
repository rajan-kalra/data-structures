#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
    private:
        void dfs(int currRowIndex, int currColIndex, vector<vector<int>> &floodFilledImage, vector<vector<int>> &inputImage, int newColor, int moveRow[], int moveCol[], int iniColor) {
            // color with new color
            floodFilledImage[currRowIndex][currColIndex] = newColor; 
            int rows = inputImage.size();
            int cols = inputImage[0].size();

            // there are exactly 4 neighbours
            for (int i = 0; i < 4; i++) {
            int newRowIndex = currRowIndex + moveRow[i];
            int newColIndex = currColIndex + moveCol[i];
            
            /**
             * conditions to be checked to apply dfs on new cell:
             * 1. New row is valid
             * 2. New col is valid
             * 3. New cell has initial color
             * 4. New cell doesn't have new color
             */
            if( (newRowIndex >= 0 && newRowIndex < rows) &&
                (newColIndex >= 0 && newColIndex < cols) &&
                (inputImage[newRowIndex][newColIndex] == iniColor) &&
                (floodFilledImage[newRowIndex][newColIndex] != newColor)) {
                dfs(newRowIndex, newColIndex, floodFilledImage, inputImage, newColor, moveRow, moveCol, iniColor); 
            }
            }
        }

    public:
        vector<vector<int>> floodFill(vector<vector<int>> &inputImage, int sr, int sc, int newColor) {
            // get initial color
            int iniColor = inputImage[sr][sc];

            // creating the copy of the input
            vector<vector<int>> floodFilledImage = inputImage;

            // delta row and delta column for neighbours
            int moveRow[] = { -1,  0, +1,  0 };
            int moveCol[] = {  0, +1,  0, -1 };

            dfs(sr, sc, floodFilledImage, inputImage, newColor, moveRow, moveCol, iniColor); 
            return floodFilledImage; 
        }
};

void printMatrix (vector<vector<int> > &image) {
    int rows = image.size();
    int cols = image[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    vector<vector<int>> inputImage {
                                {1,1,1},
                                {1,1,0},
                                {1,0,1}
                            };

    // sr = 1, sc = 1, newColor = 2
    Solution obj;
    vector<vector<int>> floodFilledImage = obj.floodFill(inputImage, 1, 1, 2);
    cout << "Matrix before flood fill: " << endl;
    printMatrix(inputImage);

    cout << "Matrix after flood fill: " << endl;
    printMatrix(floodFilledImage);

    return 0;
}