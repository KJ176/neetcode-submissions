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
    int search(vector<int>& inorder, int left, int right, int val) {
        for(int i = left; i<=right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return 0;
    }

    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int &preIndex, int left, int right) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex]);
        int inorderIndex = search(inorder, left, right, root->val);

        preIndex++;
        root -> left = builder(preorder, inorder, preIndex, left, inorderIndex - 1);
        root -> right = builder(preorder, inorder, preIndex, inorderIndex + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return builder(preorder, inorder, preIndex, 0, preorder.size() - 1);
    }
};
