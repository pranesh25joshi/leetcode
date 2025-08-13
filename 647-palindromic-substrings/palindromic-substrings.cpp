class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        map<pair<int,int>, int> memo; // 1 = palindrome, -1 = not palindrome

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome(i, j, s, memo)) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isPalindrome(int left, int right, string &s, map<pair<int,int>, int> &memo) {
        if (left >= right) return true; // single char or empty substring is palindrome
        if (memo.count({left, right})) return memo[{left, right}] == 1;

        if (s[left] == s[right] && isPalindrome(left + 1, right - 1, s, memo)) {
            memo[{left, right}] = 1;
            return true;
        } else {
            memo[{left, right}] = -1;
            return false;
        }
    }
};
