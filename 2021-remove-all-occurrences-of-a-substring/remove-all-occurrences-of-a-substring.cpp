class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = s;
        int partLen = part.size();  // store the size of part for easier reference

        for (int i = 0; i < res.size();) {
            if (res[i] == part[0]) {  // check if the first character of `part` matches
                if (res.substr(i, partLen) == part) {  // check for entire match
                    res = res.substr(0, i) + res.substr(i + partLen);  // remove the `part` from `res`
                    i = max(0, i - partLen);  // move the index back to prevent skipping over potential matches
                } else {
                    i++;  // move to the next character if no match
                }
            } else {
                i++;  // move to the next character if no match
            }
        }
        return res;
    }
};
