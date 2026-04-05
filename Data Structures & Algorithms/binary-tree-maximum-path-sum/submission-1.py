# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.res = float("-inf")

    def dfs(self, root):
        if not root:
            return 0
        
        leftPath = max(self.dfs(root.left), 0)
        rightPath = max(self.dfs(root.right), 0)

        self.res = max(self.res, root.val + leftPath + rightPath)

        return root.val + max(leftPath, rightPath)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res