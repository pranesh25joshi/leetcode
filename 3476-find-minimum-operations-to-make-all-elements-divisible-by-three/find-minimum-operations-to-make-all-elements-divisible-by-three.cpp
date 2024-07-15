class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int op: nums){
            if(op%3 != 0){
                count++;
            }
        }
        return count;
    }
};