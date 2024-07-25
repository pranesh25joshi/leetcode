class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // vector<int> jump;
        unordered_map<int,int> mapp;
        int x = 0;
        int ans = 0;
        int ep = 1;
        for(int i= 0; i<nums.size(); i++){
            x = nums[i];
            do{
                ans = ep*mapping[x%10] + ans ;
                x = x/10;
                ep = ep*10;
            }
            while(x !=0 );
            // jump.push_back(ans);
            mapp[nums[i]] = ans;
            ans = 0;
            ep = 1;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mapp[a]<mapp[b]){
                return true;
            }
            else{
                return false;
            }
            
        });
        return nums;
    }
};