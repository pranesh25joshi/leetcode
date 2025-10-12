class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        // for all array in decending order

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    // incresing order
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi; 
    }
};