class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>> targets;
        string mini = tickets[0][0];
        for(const auto& t:tickets) {
            targets[t[0]].insert(t[1]);
            mini = min({mini, t[0], t[1]});
        }

        vector<string> route;

        auto dfs = [&](auto& self, string airport) -> void {
            while(!targets[airport].empty()) {
                auto next_airport = *targets[airport].begin();
                targets[airport].erase(targets[airport].begin());
                self(self, next_airport);
            }
            route.push_back(airport);
        };

        sort(tickets.begin(), tickets.end());
        dfs(dfs, "JFK");

        reverse(route.begin(), route.end());
        return route;
    }
};
