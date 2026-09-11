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
    int count = 0;
    int res = -1;
    void inorder(TreeNode* node, int k) {
        if (node == nullptr || res != -1) {
            return;
        }
        inorder(node -> left, k);
        if (res != -1) return;
        count++;
        if (count == k) {
            res = node -> val;
        }
        inorder(node -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};
