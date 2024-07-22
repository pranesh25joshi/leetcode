class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> combined;
        
        for (int i = 0; i < names.size(); ++i) {
            combined.push_back({heights[i], names[i]});
        }

        // Sort the vector of pairs in descending order by height
        sort(combined.begin(), combined.end(), [](auto& a, auto& b) { 
            return a.first > b.first; 
        });

        // Update the names vector with sorted names
        for (int i = 0; i < combined.size(); ++i) {
            names[i] = combined[i].second;
        }

        return names;



    }
};