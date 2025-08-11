class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> ans;
        for(auto i : strs){
            string s = i;
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        for(auto i : map){
            ans.push_back(i.second);
        }
        return ans;
    }
};
