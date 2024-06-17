class Solution {
public:
    bool isInteger(double num) {
        return floor(num) == num;
    }
    bool judgeSquareSum(int c) {
        long a = 0;
        double b;
        while(a*a <= c ){
            b = sqrt(c - a*a);
            if(isInteger(b)){
                return true;
            }
            a++;
        }
        return false;
    }
};