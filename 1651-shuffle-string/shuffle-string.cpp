class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(), 'a'); ;
        int p = 0;
        for( auto i : indices){
            res[i] = s[p];
            p++;
        }
        return res;
    }
};