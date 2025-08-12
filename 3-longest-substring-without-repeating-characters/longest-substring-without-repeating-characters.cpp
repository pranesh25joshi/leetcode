class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;
        int l=0;
        int r=0;
        
        unordered_map<char,int> map;
        while(r<n){
            if(map.count(s[r]) && map[s[r]] >= l){
                l=map[s[r]]+1;
            }
            map[s[r]] = r;
            int len = r-l + 1;
            maxi= max(len,maxi);
            r++;
        }
        

        return maxi;
    }
};