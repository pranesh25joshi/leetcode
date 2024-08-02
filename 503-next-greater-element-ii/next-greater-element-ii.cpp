class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        for( int i =0 ; i< n; i++){
            int k =0;
            for( int j = i + 1; j < n + i; j++){
                if( nums[j % n] > nums[i]){
                    arr.push_back(nums[j % n]);
                    k++;
                    break;
                }
            }
            if( k==0){
                arr.push_back(-1);
            }
        }
        return arr;
    }
};