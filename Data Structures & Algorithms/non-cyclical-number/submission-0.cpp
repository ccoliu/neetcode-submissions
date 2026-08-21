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
        int iter = 0;
        while(iter < 100 && n != 1) {
            n = solve(n);
            iter++;
        }

        return n == 1;
    }
};
