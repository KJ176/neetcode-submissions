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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int levelSize = nodes.size();
            vector<int> level;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* cur = nodes.front();
                nodes.pop();

                level.push_back(cur->val);

                if(cur->left) nodes.push(cur->left);
                if(cur->right) nodes.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
