/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN; // global maximum

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // only take positive contributions (ignore negative subpaths)
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // check full path through this node
        maxSum = max(maxSum, root->val + left + right);

        // return contribution upward (pick one side)
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
