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
        unordered_set<int> st;
        st.insert(n);
        while(n != 1) {
            n = solve(n);
            if (st.find(n) != st.end()) break;
            st.insert(n);
        }

        return n == 1;
    }
};
