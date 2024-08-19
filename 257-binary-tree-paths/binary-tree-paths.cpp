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
    int  binaryPath(TreeNode* root, vector<string> &ans ,string p ){
        int a = 1;
        int b =1;
        if( root == nullptr){
            return -1;
        }
        p = p + to_string(root -> val) + "->";
        a = binaryPath( root -> left, ans , p );
        b = binaryPath( root -> right, ans, p );
        if( a == -1 && b == -1){
            ans.push_back(p.substr(0, p.length() - 2));
        }
        return 1;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        binaryPath( root , ans , "");
        return ans;
    }
};