class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> out;            // store compressed result
        char prev = chars[0];
        int cnt = 1;

        for (int i = 1; i < n; ++i) {
            if (chars[i] == prev) {
                ++cnt;
            } else {
                // write previous run
                out.push_back(prev);
                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (char c : s) out.push_back(c);
                }
                prev = chars[i];
                cnt = 1;
            }
        }

        // write the last run
        out.push_back(prev);
        if (cnt > 1) {
            string s = to_string(cnt);
            for (char c : s) out.push_back(c);
        }

        // copy back into chars' first k positions (LeetCode uses only the first k)
        for (int i = 0; i < (int)out.size(); ++i) chars[i] = out[i];

        return (int)out.size();
    }
};
