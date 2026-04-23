class Solution
{
public:
    void DEBUG_PrintDeque(const std::deque<int>& d)
    {
        for (int num : d) std::cout << num << " ";
        std::cout << std::endl;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (k == 1)
        {
            return nums;
        }

        std::vector<int> res;
        res.reserve(nums.size());

        std::deque<int> window;

        for (int i = 0; i < nums.size(); ++i)
        {
            const int leaving = i - k;
            if (leaving >= 0)
            {
                if (leaving == window.front())
                {
                    window.pop_front();
                }
            }

            const int curr = nums.at(i);

            while (!window.empty() && curr > nums.at(window.back()))
            {
                window.pop_back();
            } 
            
            window.push_back(i);

            DEBUG_PrintDeque(window);
            const int max = nums.at(window.front());

            if (i >= k - 1)
                res.push_back(max);
        }

        return res;
    }
};


/*
[1,2,1,0,4,2,6]
k = 3

curr = 1
    window = [1]
    max = window.left

curr = 2
    2 is the new max

    while 2 is greater than window.right && window is non empty,
        pop window.right off

    then add 2 to the left
    window = [2]

curr = 1
    1 is not the new max, but could be 
    the max in the future once 2 is gone
    save it away

    while 1 is greater than window.right and !empty
        pop right
    add 1 to the right

    window = [2, 1]

curr = 0
    if out of scope num == left, pop the left side

    0 not new max, but could be future max
    while 0 greater than right and empty
        pop right
    add 0 to right

curr = 4
    2 == out of scope number (index i - k)
    2 == left, pop left

    4 is the new max,
    add to right while popping off lesser elements

curr = 2
    future max case
    window : [4, 2]

curr = 6
    new max case
    window : [6] (4 and 2 kicked out by 6)







*/