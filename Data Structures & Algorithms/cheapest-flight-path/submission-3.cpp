class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n + 1, INT_MAX);
        price[src] = 0;

        for(int i=0;i<=k;i++) {
            vector<int> tmp = price;
            for(auto& s: flights) {
                if (price[s[0]] == INT_MAX) continue;

                if (price[s[0]] + s[2] < tmp[s[1]]) {
                    tmp[s[1]] = price[s[0]] + s[2];
                }
            }
            price = tmp;
        }

        return (price[dst] == INT_MAX) ? -1 : price[dst];
    }
};
