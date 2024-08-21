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
    int  Unibt( TreeNode* root ){
        if( root == nullptr){
            return -1;
        }
        int data = root -> val;
        if( root -> left){
            int a = Unibt( root -> left);
            if( a != data){
                return -1;
            }
        }
        if( root -> right){
            int b = Unibt( root -> right);
            if( b != data){
                return -1;
            }
        }
        return data;
    }
    bool isUnivalTree(TreeNode* root) {
        if( Unibt( root) == -1){
            return false;
        }
        return true;
    }
};