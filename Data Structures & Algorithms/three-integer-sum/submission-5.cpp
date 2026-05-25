class Solution {
public:
    void twoSum(const std::vector<int>& nums, int target, int curr, std::set<std::vector<int>>& hs)
    {
        std::unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == curr)
            {
                continue;
            }

            int num = nums.at(i);

            if (seen.contains(target - num)) // need target - num to sum to target
            {
                std::vector res{num, target - num};
                res.push_back(nums.at(curr));
                
                std::ranges::sort(res);
                hs.insert(res);
            }
            else
            {
                seen.insert(num);
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::set<std::vector<int>> hs;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto num = nums.at(i);
            twoSum(nums, 0 - num, i, hs);
        }

        return std::vector(hs.begin(), hs.end());
    }
};

/*
twoSum(nums, target):
    skip if already caculated this target
    return two nums that add up to target in the nums beyond startIdx

3sum():
    hash set of vectors

    for each number:
        set insert ( twoSum(nums, 0 - number) ) # ignore double insertion

    return vector{set}


target => 0 - current number

O(n^2) is fine

[2, -1, 5, 1, 0, -1]

[-1, 0, 1, 2, -1, -4] target = 0
[-1, 0, 1], [-1, 1, 2]

[0, 1, 1]
[]

[0, 0, 0]
[[0, 0, 0]]


[-1, 4, 2, -1, -8, -3, 1]
[-1, 2, -1], [-3, 2, 1], [4, -1, -3]

[0, 0, 0, 0, 0, 0, 0, 0]
[0, 0, 0]

sort each triplet and maintain a hash set of triplets to avoid double insertion

*/