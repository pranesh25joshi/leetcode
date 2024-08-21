class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            int p = i;
            bool isSelfDividing = true;

            while (p > 0) {
                int digit = p % 10;
                
                // If digit is 0 or the number is not divisible by the digit, it's not self-dividing
                if (digit == 0 || i % digit != 0) {
                    isSelfDividing = false;
                    break;
                }

                p /= 10; // Move to the next digit
            }

            // If all digits divide the number, add it to the result
            if (isSelfDividing) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
