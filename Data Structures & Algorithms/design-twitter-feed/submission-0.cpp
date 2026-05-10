class Twitter {
   public:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int time;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) { tweetMap[userId].push_back({time++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>> pq;
        followMap[userId].insert(userId);

        for (int followee : followMap[userId]) {
            auto& tweets = tweetMap[followee];
            if (!tweets.empty()) {
                int idx = tweets.size() - 1;
                pq.push({tweets[idx].first, tweets[idx].second, followee, idx});
            }
        }
        while (!pq.empty() && res.size() < 10) {
            auto temp = pq.top();
            pq.pop();

            int t = temp[0];
            int tweetId = temp[1];
            int user = temp[2];
            int idx = temp[3];
            res.push_back(tweetId);

            if (idx > 0) {
                auto& tweets = tweetMap[user];
                pq.push({tweets[idx - 1].first, tweets[idx - 1].second, user, idx - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) { followMap[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) { followMap[followerId].erase(followeeId); }
};
