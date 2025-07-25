class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i=0;i<nums1.size(); i++){
            map[nums1[i]]++;
        }
        for(auto i  : nums2){
            if(map[i]){
                ans.push_back(i);
                map[i] = map[i] - 1;
            }
        }
        return ans;
    }
};