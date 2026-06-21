class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        auto operations = [&](int n1, int n2, char op) {
            if (op == '+') {
                int n = n1 + n2;
                nums.push(n);
            }
            else if (op == '-') {
                int n = n2 - n1;
                nums.push(n);
            }
            else if (op == '*') {
                int n = n1 * n2;
                nums.push(n);
            }
            else if (op == '/') {
                int n = n2 / n1;
                nums.push(n);
            }
        };

        for(auto t:tokens) {
            if (t == "+") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                operations(n1, n2, '+');
            }
            else if (t == "-") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                operations(n1, n2, '-');
            }
            else if (t == "*") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                operations(n1, n2, '*');
            }
            else if (t == "/") {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                operations(n1, n2, '/');
            }
            else {
                nums.push(stoi(t));
            }
        }
        return nums.top();
    }
};
