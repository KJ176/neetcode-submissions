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
    int dfs(TreeNode* root, int maxSoFar) {
        if (!root) return 0;

        int res = root -> val >= maxSoFar ? 1 : 0;
        maxSoFar = max(maxSoFar, root -> val);

        res += dfs(root->left, maxSoFar);
        res += dfs(root->right, maxSoFar);

        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root -> val);
    }
};
