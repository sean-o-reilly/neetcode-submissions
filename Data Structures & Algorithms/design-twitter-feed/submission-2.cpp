struct Tweet
{
    int tweetId;
    int timestamp;
};

class Twitter
{
public:
    Twitter() = default;
    
    void postTweet(int userId, int tweetId)
    {
        users_[userId].tweets.push_front(Tweet{tweetId, time_++});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        User& user = users_[userId];
        user.following.insert(userId); // follow self

        // run min heap algo that allows at most K smallest elements into heap
        // heap grows to a size of max K. when it grows to K, we only let elements
        // larger than the min element in the heap into the heap

        // probably a way to short circuit out of the loop and save time

        auto cmp = [](Tweet& A, Tweet& B)
        {
            return A.timestamp > B.timestamp;
        };

        std::priority_queue<Tweet, std::vector<Tweet>, decltype(cmp)> pq(cmp);

        for (int followeeId : user.following)
        {
            User& followee = users_.at(followeeId);

            for (Tweet fTweet : followee.tweets)
            {
                if (pq.size() < K || fTweet.timestamp > pq.top().timestamp)
                {
                    pq.push(fTweet);
                }

                if (pq.size() > K)
                {
                    pq.pop();
                }
            }
        }

        std::vector<int> res;

        while (!pq.empty())
        {
            std::cout << pq.top().timestamp << "\n";
            res.push_back(pq.top().tweetId);
            pq.pop();
        }

        std::reverse(res.begin(), res.end());

        return res;
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
        std::list<Tweet> tweets;
    };


private:
    std::unordered_map<int, User> users_;
    const int K = 10;
    int time_ = 0;
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