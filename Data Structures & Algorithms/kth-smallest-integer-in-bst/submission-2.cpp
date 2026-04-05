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
private:
    void dfs(TreeNode* node, vector<int> &vals, int k) {
        if (!node) return;
        dfs(node->left, vals, k);
        vals.push_back(node->val);
        if(vals.size() == k) return;
        dfs(node->right, vals, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        dfs(root, vals, k);
        return vals[k-1];
    }
};
