class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;

        for (int center = 0; center < n; center++) {
            // Odd length palindrome
            expandAroundCenter(s, center, center, start, maxLen);
            // Even length palindrome
            expandAroundCenter(s, center, center + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string &s, int l, int r, int &start, int &maxLen) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }
};
