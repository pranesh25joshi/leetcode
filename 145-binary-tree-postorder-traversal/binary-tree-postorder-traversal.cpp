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
    void btPost( TreeNode* root , vector<int> &ans){
        if( root == nullptr){
            return ;
        }
        btPost( root -> left, ans);
        btPost( root -> right, ans);
        ans.push_back( root -> val);
        return ;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        btPost( root, ans);
        return ans;
    }
};