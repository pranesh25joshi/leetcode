class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        // Create pairs of (difficulty, profit) and sort by difficulty
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        sort(jobs.begin(), jobs.end());

        // Sort the workers by their abilities
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int maxProfitSoFar = 0;
        int jobIndex = 0;

        // Iterate over each worker
        for (int ability : worker) {
            // While the worker can do the current job, update the max profit so
            // far
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= ability) {
                maxProfitSoFar = max(maxProfitSoFar, jobs[jobIndex].second);
                ++jobIndex;
            }

            // Add the best job's profit the worker can do to the total max
            // profit
            maxProfit += maxProfitSoFar;
        }

        return maxProfit;
    }
};