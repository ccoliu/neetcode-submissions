class Solution {
public:
    struct Node {
        vector<Node*> children;
        string word;
        Node() {
            children.resize(26, nullptr);
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
                int idx = c - 'a';
                if (cur->children[idx] == nullptr) {
                    cur->children[idx] = new Node();
                }
                cur = cur->children[idx];
            }
            cur->word = str;
        }

        bool search(string str) {
            Node* cur = root;
            for(char c: str) {
                int idx = c - 'a';
                if (cur->children[idx] == nullptr) {
                    return false;
                }
                cur = cur->children[idx];
            }
            return true;
        }
    };

    Trie* tr;

    void dfs(vector<vector<char>>& board, Node* node, int i, int j, vector<string>& res) {
        char ch = board[i][j];
        int idx = ch - 'a';

        if (!node->children[idx]) return;

        node = node->children[idx];

        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for(int k=0;k<4;k++) {
            int nr = i + dr[k], nc = j + dc[k];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, node, nr, nc, res);
            }
        }

        board[i][j] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        tr = new Trie();
        string s = "";
        vector<string> res;
        for(string w: words) {
            tr->insert(w);
        }
        
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[i].size(); j++) {
                dfs(board, tr->root, i, j, res);
            }
        }
        
        return res;
    }
};
