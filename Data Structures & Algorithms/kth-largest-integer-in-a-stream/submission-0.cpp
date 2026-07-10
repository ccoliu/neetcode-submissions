class KthLargest {
public:
    priority_queue<int> pq;
    int kth;
    KthLargest(int k, vector<int>& nums) {
        for(auto n:nums) {
            pq.push(n);
        }
        kth = k;
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> t = pq;
        for(int i=0;i<kth - 1;i++) {
            t.pop();
        }
        return t.top();
    }
};
