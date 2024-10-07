class Solution {
public:
    int minLength(string s) {
        int x = 0;
        int y = 1;
        while(s.size() >= 2){
            if((s[x]=='A' && s[y]=='B') || (s[x]=='C' && s[y]=='D')){
                s=s.substr(0,x) + s.substr(y+1);
                x=0;
                y=1;
            }
            else{
                x++;
                y++;
            }
            if(x>=s.size() && y>=s.size()){
                return s.size();
            }
            
        }
        if(s=="AB" || s=="CD"){
            return 0;
        }
        return s.size();
    }
};