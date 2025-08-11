class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long ans = 0;
        int temp = x;
        while(temp!=0){
            ans = ans*10  + temp%10;
            temp = temp/10;
        }

        return ans==x;
    }
};