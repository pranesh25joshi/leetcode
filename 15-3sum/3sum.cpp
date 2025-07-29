class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n-2; ++i) {
            if (nums[i] > 0) break;                   // sums only grow
            if (i > 0 && nums[i] == nums[i-1]) continue;  // skip dup

            int left = i+1, right = n-1;
            while(left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    // skip duplicates on both sides:
                    while(left < right && nums[left] == nums[left+1]) ++left;
                    while(left < right && nums[right] == nums[right-1]) --right;
                    ++left; --right;
                }
                else if (s < 0) ++left;
                else --right;
            }
        }
        return res;
    }

};