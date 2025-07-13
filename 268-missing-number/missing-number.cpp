class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size() + 1;
        vector<bool> maps(size,false);

        for(auto i : nums){
            maps[i] = true;
        }
        int count = 0;
        while(maps[count] == true){
            count++;
        }

        return count;
    }
};