class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if (nums.size() <= 1) return false;
        
        int left = 0;
        int right = 0;
        std::unordered_set<int> set_;

        while (right <= k && nums.size())
        {
            if (set_.contains(nums.at(right)))
                return true;
            else set_.insert(nums.at(right));
            
            ++right;
        }

        while (right < nums.size())
        {
            set_.erase(nums.at(left));
            ++left;

            if (set_.contains(nums.at(right)))
            {
                return true;
            }
            else set_.insert(nums.at(right));
            ++right;
        }
        return false;
    }
};

/*
duplicate within sliding window of size k

left, right pointers to maintain window

right - left  == k + 1

keep a set of size k of numbers seen so far
remove nums.at(left) from set before incrementing left ptr

when incrementing right, check if the new number is in the
set AFTER evicting the old leftmost value

set = {}

while right <= k
    if set contains nums.at(right)
        return true
    else insert num
    ++right
// invalid window

while right < nums.size
    set remove nums.at(left)
    ++left

    // valid window
    if set contains nums.at(right)
        return true
    else insert nums at right

    // invalid window
    ++right
*/
