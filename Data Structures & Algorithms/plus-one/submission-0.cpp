class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        digits.back() += 1;

        int plus = 0;
        for(int i=digits.size()-1;i>=0;i--) {
            digits[i] += plus;
            plus = 0;
            if (digits[i] >= 10) {
                digits[i] %= 10;
                plus++;
            }
            ans.push_back(digits[i]);
        }
        if (plus != 0) ans.push_back(plus);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
