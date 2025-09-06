/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* isans(TreeNode* root,TreeNode* p, TreeNode* q){
        if((p->val <= root->val && root->val <= q->val) || (q->val <= root->val && root->val <= p->val) ){
            // ans = root;
            return root;
        }

        if(p->val <= root->val && q->val <= root -> val ){
            return isans(root->left, p, q);
        }
        else{
            return isans(root->right, p,q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TreeNode* ans = new TreeNode();
        return isans(root, p, q);
    }
};