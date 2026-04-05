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
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (!t1 and !t2) return true;
        if (!t1 or !t2 or t1->val != t2->val) return false;
        return isSameTree(t1->left, t2->left) and isSameTree(t1->right, t2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
