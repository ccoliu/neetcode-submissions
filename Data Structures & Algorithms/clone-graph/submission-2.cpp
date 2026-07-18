/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<vector<int>> adjs(101, vector<int>(101, 0));
        vector<int> visited(101, false);
        queue<Node*> q;
        q.push(node);
        visited[node->val] = true;
        int node_max = 1;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->neighbors.empty()) continue;
            for(auto n: node->neighbors) {
                adjs[node->val][n->val] = 1;
                adjs[n->val][node->val] = 1;
                if (!visited[n->val]) {
                    visited[n->val] = true;
                    q.push(n);
                    node_max = max(node_max, n->val);
                }
            }
        }

        vector<Node*> nodes(node_max + 1, nullptr);

        for(int i=1;i<=node_max;i++) nodes[i] = new Node(i);

        for(int i=1;i<=node_max;i++) {
            for(int j=1;j<=node_max;j++) {
                if (adjs[i][j] != 0) {
                    nodes[i]->neighbors.push_back(nodes[j]);
                }
            }
        }

        return nodes[1];
    }
};
