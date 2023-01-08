#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
  private:
    void dfs(int currRow, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int moveRow[], int moveCol[], int iniColor) {
      // color with new color
      ans[currRow][col] = newColor; 
      int n = image.size();
      int m = image[0].size();

      // there are exactly 4 neighbours
      for (int i = 0; i < 4; i++) {
        int nrow = currRow + moveRow[i];
        int ncol = col + moveCol[i];
        
        /**
         * conditions to be checked to apply dfs on new cell:
         * 1. New row is valid
         * 2. New col is valid
         * 3. New cell has initial color
         * 4. New cell doesn't have new color
         */
        if((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) && (image[nrow][ncol] == iniColor) && (ans[nrow][ncol] != newColor)) {
            dfs(nrow, ncol, ans, image, newColor, moveRow, moveCol, iniColor); 
        }
      }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
      // get initial color
      int iniColor = image[sr][sc];

      // creating the copy of the input
      vector<vector<int>> ans = image;

      // delta row and delta column for neighbours
      int moveRow[] = { -1,  0, +1,  0 };
      int moveCol[] = {  0, +1,  0, -1 };

      dfs(sr, sc, ans, image, newColor, moveRow, moveCol, iniColor); 
      return ans; 
    }
};
 
int main(){
  vector<vector<int>> image {
                              {1,1,1},
                              {1,1,0},
                              {1,0,1}
                            };
 
  // sr = 1, sc = 1, newColor = 2
  Solution obj;
  vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
  for(auto i: ans){
    for(auto j: i)
      cout << j << " ";
    cout << "\n";
  }

  return 0;
}