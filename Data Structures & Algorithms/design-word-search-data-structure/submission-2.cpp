struct Node {
    vector<Node*> children;
    bool isEnd;

    Node() {
        children.resize(27, nullptr);
        isEnd = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    bool dfs(Node* cur, int c, string str) {
        if (cur == nullptr) return false;
        if (c == str.length()) {
            return cur->isEnd;
        }
        

        bool t = false;

        if (str[c] == '.') {
            for(int i=0;i<26;i++) {
                t = t | dfs(cur->children[i], c + 1, str);
            }
            return t;
        }
        else {
            return dfs(cur->children[str[c] - 'a'], c + 1, str);
        }
    }

    void insert(string str) {
        Node* cur = root;

        for(char c:str) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }

        cur->isEnd = true;
    }

    bool searchstr(string str) {
        return dfs(root, 0, str);
    }
};

class WordDictionary {
public:
    Trie* tr;

    WordDictionary() {
        tr = new Trie();
    }
    
    void addWord(string word) {
        tr->insert(word);
    }
    
    bool search(string word) {
        return tr->searchstr(word);
    }
};
