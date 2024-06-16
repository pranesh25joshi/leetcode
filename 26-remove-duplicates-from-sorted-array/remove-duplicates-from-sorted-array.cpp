class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int *ptr = &nums[0];
        int k = 1;
        for(int i=0; i<nums.size(); i++){
            if(*ptr != nums[i]){
                *(ptr + 1) = nums[i];
                ptr = ptr + 1;
                k++;

            }
        }
        return k;
    }
};