class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans1(n, 1);
        vector<int> ans2(n, 1);
        vector<int> ans;
        ans1[0] = nums[0];
        ans2[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            ans1[i] = ans1[i-1]*nums[i];
            ans2[n- i - 1] = nums[n - i - 1]*ans2[n-i];
        }
        for(int i=0; i<n; i++){
            if(i-1<0){
                ans.push_back(ans2[i+1]);
            }
            else if(i+1>n-1){
                ans.push_back(ans1[i-1]);
            }
            else{
                ans.push_back(ans1[i-1]*ans2[i+1]);
            }
        }

        return ans;
        
    }
};