"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mapp = dict()
        mapp[None] = None

        cur = head
        while cur:
            copy = Node(cur.val)
            mapp[cur] = copy
            cur = cur.next
        
        cur = head
        while cur:
            copy = mapp[cur]
            copy.next = mapp[cur.next]
            copy.random = mapp[cur.random]
            cur = cur.next
        
        return mapp[head]

