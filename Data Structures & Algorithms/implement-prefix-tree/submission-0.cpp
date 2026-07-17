struct Node {
    vector<Node*> children;
    bool isEnd;

    Node() {
        children.resize(26, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string str) {
        Node* cur = root;
        for(char c: str) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Node();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    bool search(string str) {
        Node* cur = root;
        for(char c: str) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd;
    }

    bool searchstart(string str) {
        Node* cur = root;
        for(char c: str) {
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};

class PrefixTree {
public:
    Trie* tr;

    PrefixTree() {
        tr = new Trie();
    }
    
    void insert(string word) {
        tr->insert(word);
    }
    
    bool search(string word) {
        return tr->search(word);
    }
    
    bool startsWith(string prefix) {
        return tr->searchstart(prefix);
    }
};
