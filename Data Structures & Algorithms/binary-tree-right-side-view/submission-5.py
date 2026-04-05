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
                cur = q.popleft()
                rightMost = cur
                if cur.left: q.append(cur.left)
                if cur.right: q.append(cur.right)
            res.append(rightMost.val)
        return res