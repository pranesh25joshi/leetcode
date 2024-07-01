class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int s = arr.size();
        int count = 0;
        // int i = 0;
        // while(count != 3 && i<s){
        //     if(arr[i] % 2 != 0){
        //          count++;
        //     }
        //     else{
        //         count = 0;
        //     }
        //     i++
        // }
        for(int i = 0; i<s; i++){
            if(arr[i] % 2 != 0){
                count++;
                if(count == 3){
                    return true;
                }
            }
            else{
                count = 0;
            }
        }
        return false;
    }
};