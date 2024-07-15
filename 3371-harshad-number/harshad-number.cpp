class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int y = 0;
        int p = x;
        int count = 0;
        while(x != 0){
            y = x % 10;
            x = x/10;
            count = count + y;
        }
        return (p%count == 0) ? count : -1;
    }
};