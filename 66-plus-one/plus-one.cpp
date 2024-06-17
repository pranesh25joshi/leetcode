class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit and process towards the first digit
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            }
            // Set current digit to 0 as it was 9
            digits[i] = 0;
        }
        
        // If all digits were 9, we need to add a leading 1
        digits.insert(digits.begin(), 1);
        return digits;
    }
};