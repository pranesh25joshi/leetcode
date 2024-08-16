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
    // TreeNode* sbtree( TreeNode* root){
    //     if( root ==  nullptr){
    //         return NULL;
    //     }

    // }
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* a = NULL;
        TreeNode* b = NULL;
        if( root == nullptr){
            return NULL;
        }
        if( root -> val == val){
            return root;
        }
        if( root -> val > val){
            if( root -> left){
                 a = searchBST( root -> left, val);
            }
            else{
                return NULL;
            }

        }
        if( root -> val < val){
            if( root -> right){
                 b = searchBST( root -> right, val);
            }
            else{
                return NULL;
            }

        }

        if( a ){
            return a;
        }
        else if( b ){
            return b;
        }
        else{
            return NULL;
        }
        
    }
};