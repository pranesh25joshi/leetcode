class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for( auto num : nums){
            q.push(num);
        }
        int i = q.top() - 1;
        q.pop();
        int j = q.top() - 1;
        return i*j;
    }
};