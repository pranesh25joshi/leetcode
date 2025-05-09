class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        for(int i=0 ;i<image.size(); i++){
            for(int j=0; j<image[0].size(); j++){
                ans[i][j] = image[i][j];
            }
        }
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        int initialcolor = image[sr][sc];
        dfs(image , sr , sc , color , ans , visited , initialcolor);
        return ans;

    }

    void dfs(vector<vector<int>> &image , int sr , int sc , int color , vector<vector<int>> &ans , vector<vector<int>> &visited , int &initialcolor){
        if( (sr>=0 && sr<image.size() && sc>=0 && sc<image[0].size()) && !visited[sr][sc]){
            if(image[sr][sc] == initialcolor ){
                ans[sr][sc] = color;
                visited[sr][sc] = 1;
                dfs(image , sr , sc+1 , color , ans , visited , initialcolor);
                dfs(image , sr+1 , sc , color , ans , visited , initialcolor);
                dfs(image , sr , sc+-1 , color , ans , visited , initialcolor);
                dfs(image , sr-1 , sc , color , ans , visited , initialcolor);
            }
            return;
        }
        return;
    }
};