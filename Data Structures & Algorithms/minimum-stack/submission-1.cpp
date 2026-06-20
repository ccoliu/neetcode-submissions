class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minst.empty()) {
            minst.push(val);
        }
        else {
            int mini = min(st.top(), minst.top());
            minst.push(mini);
        }
    }
    
    void pop() {
        minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
