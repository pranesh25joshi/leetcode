class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        vector<int> ans;
        int size = nums1.size();
        for(int i =0; i<size; i++){
            map[nums1[i]] = true;
        }

        for(auto i : nums2){
            if(map[i] == true){
                ans.push_back(i);
                map[i] = false;
            }
        }
        return ans;
    }
};