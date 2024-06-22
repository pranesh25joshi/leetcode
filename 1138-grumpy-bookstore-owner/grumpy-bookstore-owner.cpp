class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int initialSatisfied = 0;

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                initialSatisfied += customers[i];
            }
        }

        int extraSatisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                extraSatisfied += customers[i];
            }
        }

        int maxExtraSatisfied = extraSatisfied;

        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                extraSatisfied += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                extraSatisfied -= customers[i - minutes];
            }
            maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);
        }

        return initialSatisfied + maxExtraSatisfied;
    }
};
