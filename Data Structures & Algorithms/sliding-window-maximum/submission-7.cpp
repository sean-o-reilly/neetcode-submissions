class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        if (k == 1) return nums;

        std::vector<int> res;
        res.reserve(nums.size() - k);

        int left = 0;
        int right = 0;

        std::deque<int> window;

        while (right < k)
        {
            while (!window.empty() && nums.at(right) > nums.at(window.front()))
            {
                window.pop_front();
            }
            window.push_front(right);
            ++right;
        }

        --right;

        while (right < nums.size())
        {
            // valid window
            res.push_back(nums.at(window.back()));

            // invalid window
            ++right;
            if (right >= nums.size()) return res;
            while (!window.empty() && nums.at(right) > nums.at(window.front()))
            {
                window.pop_front();
            }
            window.push_front(right);

            if (left == window.back()) // left goes out of scope, must be removed from deque
            {
                // leftmost values are already taken out by new max, 
                // but left could be the max leaving window
                window.pop_back(); 
            }
            ++left;
        }

        return res;
    }
};
