class Solution {
public:
int maxDistance(vector<vector<int>>& arrays) {
    int result = 0;
    int minVal = arrays[0].front();  // Minimum value from the first array
    int maxVal = arrays[0].back();   // Maximum value from the first array
    
    // Start from the second array
    for (int i = 1; i < arrays.size(); i++) {
        // Calculate the maximum distance possible using current array and stored min/max
        result = max(result, max(abs(arrays[i].back() - minVal), abs(maxVal - arrays[i].front())));
        
        // Update minVal and maxVal to include the current array's values
        minVal = min(minVal, arrays[i].front());
        maxVal = max(maxVal, arrays[i].back());
    }
    
    return result;
}

};
