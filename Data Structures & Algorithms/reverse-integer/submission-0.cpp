class Solution {
public:
    int reverse(int x) {
        long long check_high = INT_MAX;
        long long check_low = INT_MIN;
        bool minus = false;

        string res = to_string(x);
        if (res[0] == '-') {
            minus = true;
            res.erase(res.begin());
        }

        long long ans = 0;
        while(!res.empty()) {
            cout << res << endl;
            ans *= 10;
            ans += (res.back() - '0');
            res.pop_back();
        }

        if (minus) ans = -ans;
 
        if (ans > check_high || ans < check_low) return 0;
        else return (int)ans;
    }
};
