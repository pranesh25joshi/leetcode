class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        int k;
        sort(nums.begin(),nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] >= nums[i]){
                k = nums[i];
                nums[i] = nums[i] + abs(nums[i] - nums[i-1]) + 1;
                count = count + abs(k - nums[i-1]) + 1;
            }
        }
        return count;
    }
};