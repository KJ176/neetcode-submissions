# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        q = deque([root])
        res = []

        while q:
            rightMost = None
            levelSize = len(q)

            for _ in range(levelSize):
                rightMost = q.popleft()
                # rightMost = cur
                if rightMost.left: q.append(rightMost.left)
                if rightMost.right: q.append(rightMost.right)
            res.append(rightMost.val)
        return res