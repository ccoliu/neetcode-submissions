class Node {
    public:
        Node* next;
        Node* prev;
        int key;
        int val;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    int cap;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;
        p->next = n;
        n->prev = p;
    }

    void insert(Node* node) {
        Node* n = right->prev;
        n->next = node;
        node->next = right;
        node->prev = n;
        right->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* n = cache[key];
            n->val = value;
            remove(n);
            insert(n);
            return;
        }

        if (cache.size() == cap) {
            Node* rm = left->next;
            cache.erase(rm->key);
            remove(rm);
        }

        Node* n = new Node(key, value);
        cache[key] = n;
        insert(n);
    }
};
