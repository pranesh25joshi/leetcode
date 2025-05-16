class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        // Multi-source BFS: push all 0s in the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                }
            }
        }

        // Directions: up, right, down, left
        vector<pair<int, int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();

            ans[r][c] = step;

            for(auto [dr, dc] : dir){
                int newr = r + dr;
                int newc = c + dc;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && !visited[newr][newc]){
                    visited[newr][newc] = 1;
                    q.push({{newr, newc}, step + 1});
                }
            }
        }

        return ans;
    }
};
