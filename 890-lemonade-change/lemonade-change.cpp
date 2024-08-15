class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0;
        int c10 = 0;
        // int c20 = 0;
        for( auto i : bills){
            if(i == 5)
                c5++;
            else if( i == 10){
                c10++;
                c5--;
                if( c5 < 0)
                    return false;
            }
            else{
                if (c5 > 0 && c10 > 0) {
                    c5--;
                    c10--;
                } else if (c5 > 2) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};