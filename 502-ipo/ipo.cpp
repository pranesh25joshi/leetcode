class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        // Create a vector of pairs where each pair is (capital, profit)
        std::vector<std::pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Sort the projects by their capital requirements
        std::sort(projects.begin(), projects.end());

        // Use a max-heap to store the profits of projects that we can start
        std::priority_queue<int> maxHeap;

        int index = 0;
        for (int i = 0; i < k; ++i) {
            // Add all the projects we can afford to start to the max-heap
            while (index < projects.size() && projects[index].first <= w) {
                maxHeap.push(projects[index].second);
                ++index;
            }

            // If there are no projects we can start, break out of the loop
            if (maxHeap.empty()) {
                break;
            }

            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};