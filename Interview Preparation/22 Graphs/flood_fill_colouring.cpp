/*
    Leetcode Problem Link: https://leetcode.com/problems/flood-fill/
*/
class Solution {
public:
    void dfs_helper(vector<vector<int>> &image, int r, int c, int oldColor, int newColor) {
        int rows = image.size(), cols = image[0].size();
        // base condition
        if(r < 0 || c < 0 || r >= rows || c >= cols)
            return;
        
        // transform the color
        image[r][c] = newColor;
        
        // make recursive calls on the 4 neighbours if they exist and are connected
        if(r + 1 < rows and image[r + 1][c] == oldColor)
            dfs_helper(image, r + 1, c, oldColor, newColor);
        if(r - 1 >= 0 and image[r - 1][c] == oldColor)
            dfs_helper(image, r - 1, c, oldColor, newColor);
        if(c + 1 < cols and image[r][c + 1] == oldColor)
            dfs_helper(image, r, c + 1, oldColor, newColor);
        if(c - 1 >= 0 and image[r][c - 1] == oldColor)
            dfs_helper(image, r, c - 1, oldColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        // initiate a dfs call with the source pixel
        if(oldColor != newColor) {
            dfs_helper(image, sr, sc, oldColor, newColor);
        }
        return image;
    }
};