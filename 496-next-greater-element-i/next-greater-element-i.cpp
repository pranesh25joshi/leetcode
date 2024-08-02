class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> ans;
        int n = nums2.size();
        for( int i = 0 ; i < n - 1 ; i++ ){
            for( int j = i + 1 ; j < n ; j++ ){
                if( nums2[j] > nums2[i] ){
                    umap[nums2[i]] = nums2[j];
                    break;
                }
                umap[nums2[i]] = -1;
            }
        }
        umap[nums2[n-1]] = -1;
        
        for( int num : nums1 ){
            ans.push_back(umap[num]);
        }
        return ans;
    }
};