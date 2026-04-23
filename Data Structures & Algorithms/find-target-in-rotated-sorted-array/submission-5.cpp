class Solution {
public:
    int binarySearch(vector<int>& nums, int search, int low, int high)
    {
        while (low <= high)
        {
            int mid = (high + low) / 2;
            int res = nums.at(mid);

            if (res == search)
            {
                return mid;
            }
            else if (search > res)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }

    int splitIdxSearch(vector<int>& nums)
    {
        int high = nums.size() - 1;
        int low = 0;

        while (low < high)
        {
            int mid = (high + low) / 2;
            
            int left = mid - 1;
            if (left >= 0)
            {
                if (nums.at(mid) < nums.at(left))
                    return mid;
            }

            int right = mid + 1;
            if (right < nums.size())
            {
                if (nums.at(right) < nums.at(mid))
                    return right;
            }

            if (nums.at(high) < nums.at(low))
            {
                if (nums.at(mid) > nums.at(high))
                {
                    low = mid + 1;
                }
                else if (nums.at(mid) < nums.at(high))
                {
                    high = mid - 1;
                }
            }
            else
            {
                return low;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;
        if (nums.size() == 1)
        {
            return target == nums[0] ? 0 : -1;
        }

        int splitIdx = splitIdxSearch(nums);
        std::cout << "Split: " << splitIdx;

        int lowerRes = binarySearch(nums, target, 0, splitIdx - 1);
        int highRes = binarySearch(nums, target, splitIdx, nums.size() - 1);

        if (lowerRes != -1) return lowerRes;
        else if (highRes != -1) return highRes;

        return -1;
    }
};

/*

Two sorted segments

Use binary sesarch to find the split between segments in logn

Use binary search on each segment to find the number

logn + logn + logn = O(logn) time complexity


How to find split index?

if mid < mid - 1, return mid
if mid > mid + 1, return mid + 1

if high num < low num, and mid is greater than high num, 
    split is to the right

if high num < low num, and mid is less than higih num,
    split is to left

else if low num < high num, split is low num

[4, 5, 6, 7, 8, 9, 1, 2, 3]

[2, 3, 4, 5, 6, 7, 8, 9, 1]

[9, 1, 2, 3, 4, 5, 6, 7, 8]






*/