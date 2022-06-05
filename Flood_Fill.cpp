class Solution {
public:
    void helper(vector<vector<int>>& image,int sr,int sc,int newColor,int oldColor)
    {
        if((sr<0) or (sc<0) or(sr==image.size()) or (sc==image[sr].size()))
           return;
        if(image[sr][sc]==oldColor)
        {
            image[sr][sc]=newColor;
            helper(image,sr-1,sc,newColor,oldColor);
            helper(image,sr+1,sc,newColor,oldColor);
            helper(image,sr,sc-1,newColor,oldColor);
            helper(image,sr,sc+1,newColor,oldColor);
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor=image[sr][sc];
        if(newColor!=oldColor)
            helper(image,sr,sc,newColor,oldColor);
        return image;
    }
};