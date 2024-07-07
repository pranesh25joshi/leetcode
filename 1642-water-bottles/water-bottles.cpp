class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0;
        while(numBottles >= numExchange){
            numBottles = numBottles - numExchange + 1;
            count = count + numExchange;

        }
        return count + numBottles;
    }
};