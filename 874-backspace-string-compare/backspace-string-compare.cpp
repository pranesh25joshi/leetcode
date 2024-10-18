class Solution {
public:
    string backSpaceremover(string s){
        for( int i = 0 ; i< s.size();){
            if(s[i] == '#'){
                if(i == 0){
                    s.erase(i, 1);
                    i = max(0, i-1);
                }
                else{
                    s.erase(i-1,2);    
                    i = max(0, i-2);
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
    bool backspaceCompare(string s, string t) {
        return (backSpaceremover(s) == backSpaceremover(t))? true : false;
    }
};