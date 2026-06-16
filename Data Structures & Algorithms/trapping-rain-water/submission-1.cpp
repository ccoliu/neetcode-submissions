class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> wall;
        int ans = 0;

        for(int i=0;i<n;i++) {
            while (!wall.empty() && height[wall.top()] < height[i]) {
                int mid = wall.top();
                wall.pop();
                if (wall.empty()) break;
                int left = wall.top();
                int w = i - left - 1;
                int h = min(height[left], height[i]) - height[mid];
                ans += w * h;
            }
            wall.push(i);
        }

        return ans;
    }
};
