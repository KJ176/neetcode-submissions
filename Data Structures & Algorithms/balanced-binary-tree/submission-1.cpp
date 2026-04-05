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
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int lh = dfs(root -> left);
        if (lh == -1) return -1; // Short-circuit

        int rh = dfs(root -> right);
        if (rh == -1) return -1; // Short-circuit

        if(abs(lh - rh) > 1) {
            return -1; // Short-circuit
        }

        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
