class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetmap;
    unordered_map<int, set<int>> followmap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [](const vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        followmap[userId].insert(userId);

        for(int f: followmap[userId]) {
            if (tweetmap.count(f)) {
                const vector<vector<int>>& tweets = tweetmap[f];
                int idx = tweets.size() - 1;
                pq.push({tweets[idx][0], tweets[idx][1], f, idx});
            }
        }

        while(!pq.empty() && res.size() < 10) {
            vector<int> cur = pq.top();
            pq.pop();
            res.push_back(cur[1]);
            int idx = cur[3];

            if (idx > 0) {
                const vector<int>& tweet = tweetmap[cur[2]][idx - 1];
                pq.push({tweet[0], tweet[1], cur[2], idx - 1});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
