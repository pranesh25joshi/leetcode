class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int m = worker.size();
        int n = profit.size();
        int maxi = 0;

        vector<bool> completed(n, false);
        for(int i= 0; i<m ;i++){
            int maxe =0;
            for(int j =0 ; j<n; j++){
                if(difficulty[j] <= worker[i]){
                    maxe = max(maxe, profit[j]);
                }
            }
            maxi = maxi + maxe;
        }
        return maxi;

}
}
;