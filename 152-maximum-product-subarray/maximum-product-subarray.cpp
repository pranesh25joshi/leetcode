class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minsofar = nums[0];
        int maxsofar = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(minsofar,maxsofar);
            }
            minsofar = min(nums[i], minsofar*nums[i]);
            maxsofar = max(nums[i], maxsofar*nums[i]);
            ans = max(ans, maxsofar);

        }

        return ans;
    }
};