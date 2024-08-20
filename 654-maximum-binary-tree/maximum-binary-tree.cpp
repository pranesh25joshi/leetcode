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
    TreeNode* MaxiBinaryTree(vector<int> &nums, int low , int high){
        if (low >= high) {
            return nullptr; // Base case: no elements to form a tree
        }
        
        int maxi = low; // Initialize maxi to low
        for( int  i=low ; i<high; i++){
            if( nums[i]  > nums[maxi]){
                maxi = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxi]);
        root -> left = MaxiBinaryTree( nums , low , maxi);
        root -> right = MaxiBinaryTree( nums, maxi + 1, high);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        int low = 0;
        int high = nums.size();
        return MaxiBinaryTree(nums, low , high);
    }
};