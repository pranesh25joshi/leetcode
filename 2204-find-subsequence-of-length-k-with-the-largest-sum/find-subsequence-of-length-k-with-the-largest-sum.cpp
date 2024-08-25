class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> ans;
        for( int  i =0 ; i< nums.size(); i++){
            q.push({nums[i], i});
        }
        while( k >0){
            ans.push_back(q.top().second);
            q.pop();
            k--;
        }
        sort(ans.begin(), ans.end());
        for( int  i =0; i< ans.size(); i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};