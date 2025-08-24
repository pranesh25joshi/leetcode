class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;

        // swap left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // recursively invert children
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
