/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (!root) return "%,"; // use % to mark nulls

    string ans = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        if (temp) {
            ans += to_string(temp->val) + ",";
            q.push(temp->left);
            q.push(temp->right);
        } else {
            ans += "%,";
        }
    }
    return ans;
}


    // Decodes your encoded data to tree.
    // Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.empty()) return nullptr;

    // Split string into tokens (values and %)
    vector<string> nodes;
    string temp = "";
    for (char c : data) {
        if (c == ',') { 
            nodes.push_back(temp);
            temp = "";
        } else {
            temp.push_back(c);
        }
    }
    if (!temp.empty()) nodes.push_back(temp);

    if (nodes[0] == "%") return nullptr;

    // Create root
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        // Left child
        if (nodes[i] != "%") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != "%") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));