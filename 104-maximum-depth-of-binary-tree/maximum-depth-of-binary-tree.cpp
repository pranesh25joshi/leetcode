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
    void maxi(TreeNode* root, int count , int &maxii){
        if(root==nullptr){
            maxii = max(maxii,count);
            return ;
        }
        maxi(root->left, count+1, maxii);
        maxi(root->right, count+1, maxii);

        return;

    }
    int maxDepth(TreeNode* root) {
        int count = 0;
        int maxii = 1;
        if(root==nullptr){
            return 0;
        }
        maxi(root, count, maxii);

        return maxii;
    }
};