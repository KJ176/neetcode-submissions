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
        Node* before = node -> prev;
        Node* after = node -> next;
        before -> next = after;
        after -> prev = before;
    }

    void insert(Node* node) {
        Node* prev = right -> prev;
        prev -> next = node;
        node -> prev = prev;
        node -> next = right;
        right -> prev = node;
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
            remove(mapp[key]);
        }
        Node* newNode = new Node(key, value);
        mapp[key] = newNode;
        insert(newNode);

        if (mapp.size() > cap) {
            Node* lru = left -> next;
            remove(lru);
            mapp.erase(lru -> key);
            delete lru;
        }
    }
};
