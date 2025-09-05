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
    bool ansis(TreeNode* root , int &k, int &ans){
        if(!root){
            return false;
        }
        // k = 3, 2 , 1 , 
        if(ansis(root->left , k , ans)){
            return true;
        }
        k--;
        if(k==0){
            ans = root->val;
            return true;
        }
        if(ansis(root->right, k,ans)){
            return true;
        }
        return false;

    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        ansis(root, k, ans);
        return ans;
    }
};