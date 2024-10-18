class Solution {
public:
    bool rotateString(string s, string goal) {
        string a = s;
        int count = s.size();
        while( count > 0 ){
            if( a == goal ){
                return true;
            }
            else{
                a = a.substr(1) + a[0];
                count--;
            }
        }
        return false;
    }
};