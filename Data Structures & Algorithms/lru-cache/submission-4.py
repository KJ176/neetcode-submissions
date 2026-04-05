class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}

        self.left, self.right = Node(0, 0), Node(0,0)
        self.left.next = self.right
        self.right.prev = self.left
    
    def remove(self, node):
        beforeNode = node.prev
        afterNode = node.next

        beforeNode.next = afterNode
        afterNode.prev = beforeNode

    def insert(self, node):
        beforeNode = self.right.prev
        beforeNode.next = node
        node.prev = beforeNode
        node.next = self.right
        self.right.prev = node

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            self.insert(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.val = value
            self.remove(node)
            self.insert(node)
        else:
            newNode = Node(key, value)
            self.insert(newNode)
            self.cache[key] = newNode
            if len(self.cache) > self.cap:
                lru = self.left.next
                self.remove(lru)
                del self.cache[lru.key]
