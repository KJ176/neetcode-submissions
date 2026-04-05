/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapp;
        mapp[nullptr] = nullptr;
        
        Node* cur = head;
        while (cur != nullptr) {
            mapp[cur] = new Node(cur -> val);
            cur = cur -> next;
        }

        cur = head;
        while (cur != nullptr) {
            Node* copy = mapp[cur];
            copy -> next = mapp[cur -> next];
            copy -> random = mapp[cur -> random];
            cur = cur -> next;
        }

        return mapp[head];
    }
};
