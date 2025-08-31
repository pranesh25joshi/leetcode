class Solution {
public:
    // helper to check if two trees are identical
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;       // both null → identical
        if (!s || !t) return false;      // one null, one not → not identical
        if (s->val != t->val) return false; // values differ
        
        // check left and right subtrees
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; // base: empty tree can’t contain non-empty subtree
        if (isSameTree(root, subRoot)) return true; // check at current node
        // else check in left or right subtree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
