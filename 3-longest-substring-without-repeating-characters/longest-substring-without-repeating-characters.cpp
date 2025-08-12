class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;

        for(int i=0; i<n; i++){
            unordered_map<char, int> map;
            for(int j=i; j<n; j++){
                if(map[s[j]]){
                    break;
                }
                int len = j-i + 1;
                maxi = max(len, maxi);
                map[s[j]] = 1;
            }
        }

        return maxi;
    }
};