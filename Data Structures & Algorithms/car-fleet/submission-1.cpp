class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        
        for(int i = 0;i<n;i++) {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        vector<double> stack;
        for(auto &c: cars) {
            stack.push_back(((double)target - c.first) / c.second);
            if (stack.size() >= 2 && stack[stack.size() - 1] <= stack[stack.size() - 2]) {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
