class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int totalElements = original.size();
        
        // Check if reshape is possible
        if (totalElements != m * n) {
            return {}; // Return an empty 2D array
        }
        
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        int index = 0;
        // Fill the 2D array
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = original[index++];
            }
        }
        
        return result;

    }
};