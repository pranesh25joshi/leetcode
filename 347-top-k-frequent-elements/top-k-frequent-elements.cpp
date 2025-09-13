class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> map;
        for(auto i : nums){
            map[i]++;
        }
        vector<int> ans;

        vector<pair<int, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        for(auto i : vec){
            if(k>0){
                ans.push_back(i.first);
            }
            k--;
        }

     return ans;

    }
};