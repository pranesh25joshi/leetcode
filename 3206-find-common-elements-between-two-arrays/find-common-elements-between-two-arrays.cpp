class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,bool> map1;
        unordered_map<int ,bool> map2;
        vector<int> ans;
        int count = 0;
        for(auto i : nums1){
            map1[i] = true;
        }
        for(auto i : nums2){
            map2[i] = true;
        }
        for(auto i : nums1){
            if(map2[i]){
                count++;
            }
        }
        ans.push_back(count);
        count=0;
        for(auto i : nums2){
            if(map1[i]){
                count++;
            }
        }
        ans.push_back(count);
        return ans;
    
    }
};