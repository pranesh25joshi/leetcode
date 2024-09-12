class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, bool> mp;
        for(auto i : allowed){
            mp[i] = true;
        }
        int count = 0;
        for( auto i : words){
            bool p = true;
            for( auto j  : i){
                if(!mp[j]){
                    p = false;
                    break;
                }
            }
            if(p){
                count++;
            }
        }
        return count;
    }
};