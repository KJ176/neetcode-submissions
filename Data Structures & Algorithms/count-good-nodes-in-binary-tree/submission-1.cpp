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
    int dfs(TreeNode* root, int maxSoFar) {
        if (!root) return 0;
        int res = 0;
        if (root->val >= maxSoFar) {
            res = 1;
            maxSoFar = root->val;
        }
        res += dfs(root->left, maxSoFar);
        res += dfs(root->right, maxSoFar);

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
