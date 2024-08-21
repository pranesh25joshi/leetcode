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
    TreeNode* removeZero( TreeNode* root){
        if( root == nullptr ){
            return nullptr;
        }
        root -> left = removeZero( root -> left);
        root -> right = removeZero( root -> right);
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return removeZero( root);
    }
};