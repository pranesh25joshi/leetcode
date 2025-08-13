class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);  // frequency of each letter
        int left = 0, maxCount = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add the current char to frequency
            freq[s[right] - 'A']++;
            // Track most frequent char in the current window
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If more than k changes are needed, shrink window from left
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update maxLength
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
