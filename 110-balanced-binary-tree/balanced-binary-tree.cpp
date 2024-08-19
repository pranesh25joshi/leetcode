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

    int Balanced( TreeNode* root ){
        if( root == nullptr){
            return 0;
        }
        int  a = Balanced( root -> left );
        if( a == -1){
            return -1;
        }
        int  b = Balanced( root -> right );
        if( b == -1){
            return -1;
        }
        if( abs( a - b) > 1){
            return -1;
        }
        return max( a, b ) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(Balanced( root ) != -1 ){
            return true;
        }
        return false;
    }
};