class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1; // important to handle subarrays starting from index 0

        int currentsum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            currentsum += nums[i];

            if (map.find(currentsum - k) != map.end()) {
                count += map[currentsum - k];
            }

            map[currentsum]++;
        }

        return count;
    }
};
