class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans(3, 0);
        int size = nums.size();
        vector<int> final(size);
        for(auto i : nums){
            ans[i]++;
        }
        int count = 0;
        for(int i=0; i<3; i++){
            for(int j=0;j<ans[i];j++){
                nums[count++] = i;
            }
        }
    }
};