class Twitter {
    int counter;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter() {
        counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ counter++, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto &t: tweets[userId]) {
            minHeap.push(t);
            if (minHeap.size() > 10) {
                minHeap.pop();
            }
        }

        for (int user: followMap[userId]) {
            for (auto &t: tweets[user]) {
                minHeap.push(t);
                if (minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }

        while(!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
