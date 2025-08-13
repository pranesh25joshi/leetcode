class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        map<pair<int, int>, int> map;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(map[{i,j}] == 0){
                    if(finding(i, j, s)){
                        map[{i,j}] = 1;
                        count++;
                    
                    }
                    else{
                        map[{i,j}] = -1;
                    }
                }
                else if(map[{i,j}] == 1){
                    count++;
                }
                else{

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