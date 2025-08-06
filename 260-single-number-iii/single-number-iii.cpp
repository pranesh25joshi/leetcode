class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long horimiya = 0;
        for( auto i : nums){
            horimiya = horimiya^i;
        }

        int diff = horimiya&(-horimiya);

        int x =0 ;
        int y = 0 ;
        for(auto i : nums){
            if(diff&i){
                 x = x^i;
            }
            else{
                y = y^i;
            }
        }

        return {x, y};
    }
};