class Twitter {
public:
    Twitter() = default;
    
    void postTweet(int userId, int tweetId)
    {
        tweets_.push_front(Tweet{userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        vector<int> resTweets;

        for (auto tweet : tweets_)
        {
            if (users_[userId].following.count(tweet.posterId) || tweet.posterId == userId)
            {
                resTweets.push_back(tweet.tweetId);
            }
            if (resTweets.size() >= K)
            {
                break;
            }
        }

        return resTweets;
    }
    
    void follow(int followerId, int followeeId)
    {
        users_[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        users_[followerId].following.erase(followeeId);
    }

    struct User
    {
        std::unordered_set<int> following;
    };

    struct Tweet
    {
        int posterId;
        int tweetId;
    };

private:

    std::unordered_map<int, User> users_;
    std::list<Tweet> tweets_; // most recent tweets at front
    const int K = 10;
};


/*

hashtable of users
    maps from userID->User

    struct User contains:
        set of UserIDs the user follows
    
    follow and unfollow in amortized O(1)


linked list of tweets
    on post tweet:
        push the tweet to front of list
        O(1)
    on getNewsFeed 
        traverse front to back, finding at most 
        10 tweets that contain matches in UserID's following set
        O(n)




*/