class Solution {
public:
    bool check(vector<int>& nums) {
        int it = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            for(int j = i; j< i + n - 1; j++){
                if(nums[j%n] > nums[(j+1)%n]){
                    break;
                }
                else{
                    it++;
                }
            }
            if(it == n -1){
                return true;
            }
            it = 0;
        }
        return false;
    }
};