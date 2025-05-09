class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int ans = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    ans++;  // count one island
                }
            }
        }

        return ans;
    }

private:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary and visited checks
        if (i < 0 || i >= rows || j < 0 || j >= cols ||
            grid[i][j] == '0' || visited[i][j]) return;

        visited[i][j] = true;

        // Explore all 4 directions
        dfs(i + 1, j, grid, visited);  // down
        dfs(i - 1, j, grid, visited);  // up
        dfs(i, j + 1, grid, visited);  // right
        dfs(i, j - 1, grid, visited);  // left
    }
};
