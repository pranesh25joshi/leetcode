class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for(int i : nums){
            mapp[i]++;
        }

        vector<pair<int, int>> vec(mapp.begin(), mapp.end());
        sort(vec.begin(), vec.end(), [&](const pair<int, int>& a,      const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        return vec.begin() -> first;
         
        
    }
};