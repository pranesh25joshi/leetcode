class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(finding(i, j, s)){
                    count++;
                }

            }
        }
        return count;  
    }
    bool finding(int left, int right, string &s){


                while(left <right){
                    if(s[left] == s[right]){
                        left++;
                        right--;
                    }
                    else{
                        return false;
                                        }
                }
                return true;
    }
};