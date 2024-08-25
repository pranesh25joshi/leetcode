class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        // map<int, int> mp;
        for( int i = 0; i< mat.size(); i++){
            int count = 0;
            for(int j = 0; j< mat[0].size(); j++){
                if( mat[i][j] == 0){
                    break;
                }
                // mp[i]++;
                count++;
            }
            if( q.size() < k){
                q.push({count, i});
            }
            else{
                if( count < q.top().first){
                    q.pop();
                    q.push({count, i});
                }
            
            }
        }

        while(!q.empty()){
            ans.insert(ans.begin(), q.top().second);
            q.pop();
        }
        return ans;
    }
};