class Solution {
public:
    bool isPalindrome(int x) {
        string p = to_string(x);
        string ans = "";
        for(auto i : p){
            ans = i + ans;
        }
        return p==ans;
    }
};