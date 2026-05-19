class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        if (nums.empty()) return 0;
        if (std::accumulate(nums.begin(), nums.end(), 0) < target) return 0;

        int left = 0;
        int right = 0;
        int sum = nums.at(0);
        int min = std::numeric_limits<int>::max();

        while (right < nums.size())
        {
            if (sum < target)
            {
                ++right;
                if (right >= nums.size()) return min;
                sum += nums.at(right);
            }
            else
            {
                min = std::min(min, right - left + 1);
                sum -= nums.at(left);
                ++left;
                right = std::max(right, left);
            }
        }

        return min;
    }
};


/*
smallest width window
where sum of window >= target

sliding window
rolling sum

left and right are indices
expand right while sum < target
    ++right
shrink left while sum >= target
    update minWidth
    ++left
width = right - left + 1

[2,1,5,1,5,3]
[1,2,1]

[1, 1, 1, 999, 1, 1]
[1, 2, 3, 4, 5, 6]
[6, 5, 4, 3, 2, 1]
[]
[1, 2]

*/