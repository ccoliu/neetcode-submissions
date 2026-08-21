class Solution {
public:
    int solve(int n) {
        int ans = 0;
        while(n != 0) {
            int t = n % 10;
            ans += t * t;
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = solve(n);

        while(fast != slow && fast != 1) {
            slow = solve(slow);
            fast = solve(solve(fast));
        }

        return fast == 1;
    }
};
