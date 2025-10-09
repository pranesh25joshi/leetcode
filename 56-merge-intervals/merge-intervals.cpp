class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a , const vector<int> &b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;

        int initial = intervals[0][0];
        int afterwardd = intervals[0][1];


        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= afterwardd){
                afterwardd = max(afterwardd, intervals[i][1]);
            }else{
                ans.push_back({initial, afterwardd});
                initial = intervals[i][0];
                afterwardd = intervals[i][1];
            }
        }
         ans.push_back({initial, afterwardd});

         return ans;

    }
};