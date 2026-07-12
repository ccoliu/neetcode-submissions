// 找 MinHeap 最大 + MaxHeap 最小
class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<>> min_pq;
    int len;
    MedianFinder() {
        len = 0;
    }
    
    void addNum(int num) {
        len++;
        if (len == 1) {
            min_pq.push(num);
            return;
        }

        if (!min_pq.empty() && num > min_pq.top()) {
            min_pq.push(num);
            if (min_pq.size() - max_pq.size() >= 2) {
                max_pq.push(min_pq.top());
                min_pq.pop();
            } 
        }
        else {
            max_pq.push(num);
            if (max_pq.size() - min_pq.size() >= 2) {
                min_pq.push(max_pq.top());
                max_pq.pop();
            }
        }
    }
    
    double findMedian() {
        if (len % 2 == 1) {
            return (max_pq.size() > min_pq.size()) ? max_pq.top() : min_pq.top();
        }
        else return ((double)(max_pq.top() + min_pq.top()) / 2);
    }
};
