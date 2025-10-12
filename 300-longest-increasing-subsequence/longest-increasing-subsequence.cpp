class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp; // stores the smallest tail for subsequences of each length
        
        for (int num : nums) {
            // find the position to replace (first element >= num)
            auto it = lower_bound(temp.begin(), temp.end(), num);
            
            if (it == temp.end()) {
                // if num is greater than all elements, extend the subsequence
                temp.push_back(num);
            } else {
                // else replace the first element >= num
                *it = num;
            }
        }
        return temp.size(); // the number of piles = LIS length
    }
};
