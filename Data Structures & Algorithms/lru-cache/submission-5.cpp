class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mapp;
    Node* left; 
    Node* right;

    void remove(Node* node) {
        Node* beforeNode = node -> prev;
        Node* afterNode = node -> next;
        beforeNode -> next = afterNode;
        afterNode -> prev = beforeNode;
    }

    void insert(Node* node) {
        Node* beforeNode = right -> prev;
        beforeNode -> next = node;
        node -> prev = beforeNode;
        right -> prev = node;
        node -> next = right;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        mapp.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) {
        if (mapp.find(key) != mapp.end()) {
            Node* node = mapp[key];
            remove(node);
            insert(node);
            return node -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mapp.find(key) != mapp.end()) {
            Node* node = mapp[key];
            node -> val = value;
            remove(node);
            insert(node);
        } else {
            Node* newNode = new Node(key, value);
            insert(newNode);
            mapp[key] = newNode;

            if (mapp.size() > cap) {
                Node* lru = left -> next;
                remove(lru);
                mapp.erase(lru -> key);
                delete lru;
            }
        }
    }
};
