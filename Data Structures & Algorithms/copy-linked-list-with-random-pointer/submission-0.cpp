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
        Node* cur = head;
        vector<Node*> nodes;
        unordered_map<Node*,Node*> mp;

        Node* dummy = new Node(0);
        Node* ans = dummy;

        while(cur) {
            ans->next = new Node(cur->val);
            ans = ans->next;
            mp[cur] = ans;
            cur = cur->next;
        }


        cur = head;
        ans = dummy->next;
        

        while(cur) {
            if (cur->random == nullptr) {
                ans->random = nullptr;
            }
            else {
                ans->random = mp[cur->random];
            }

            ans = ans->next;
            cur = cur->next;
        }

        ans = dummy->next;
        delete dummy;
        return ans;
    }
};
