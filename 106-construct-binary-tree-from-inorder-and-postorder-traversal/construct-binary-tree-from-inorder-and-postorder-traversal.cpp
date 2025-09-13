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
    unordered_map<int, int> inorderIndex;  // to store value -> index mapping
    int postIdx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // pick root from postorder
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // split inorder around root
        int inRootIdx = inorderIndex[rootVal];

        // build right first, then left
        root->right = build(inorder, postorder, inRootIdx + 1, inEnd);
        root->left  = build(inorder, postorder, inStart, inRootIdx - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size() - 1;

        // build hashmap for inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
