class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> freq(2001, 0);
        vector<int> num;
        for(auto n:nums) {
            freq[n + 1000]++;
            if (freq[n + 1000] == 1) num.push_back(n);
        }
        sort(num.begin(), num.end(), [&](int a, int b) {
            return freq[a + 1000] > freq[b + 1000];
        });

        return vector<int>(num.begin(), num.begin() + k);
    }
};
