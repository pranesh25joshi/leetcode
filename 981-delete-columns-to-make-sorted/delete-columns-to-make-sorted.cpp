class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for( int i= 0; i< strs[0].size(); i++){
            char mini = '\0';
            for( auto j: strs){
                if(mini <= j[i]){
                    mini = j[i];
                }
                else{
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};