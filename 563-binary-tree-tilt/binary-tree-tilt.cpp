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
    int BinaryTilt( TreeNode* root , int &sum){
        if( root == nullptr){
            return 0;
        }
        int a = BinaryTilt(root -> left, sum );
        int b = BinaryTilt(root -> right, sum );
        sum = sum  + abs(a - b);
        return root -> val + b + a;

    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        BinaryTilt(root, sum );
        return sum;
    }
};