class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort by end time (greedy choice)
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int count = 1;                 // Keep at least one interval
        int end = intervals[0][1];     // End time of the last kept interval

        // Step 2: Select non-overlapping intervals greedily
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                // Non-overlapping → keep it
                count++;
                end = intervals[i][1];
            }
            // else → overlapping, skip (i.e., "remove" it)
        }

        // Step 3: Total removals = total - kept
        return intervals.size() - count;
    }
};
