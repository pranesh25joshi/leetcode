class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        int j = k;
        for( int i =0 ; i< chalk.size(); i++){
            if( j< chalk[i]){
                return i;
            }
            j = j - chalk[i];
            sum = sum + chalk[i];
        }
        k = k % sum;
        for( int i =0 ; i< chalk.size(); i++){
            if( k< chalk[i]){
                return i;
            }
            k = k - chalk[i];
        }
        return 0;
    }
};