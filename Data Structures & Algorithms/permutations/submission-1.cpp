class Solution {
public:
    template <typename T>
    void printVector(const std::vector<T>& vec)
    {
        std::cout << "[";
        for (const T& element : vec)
        {
            std::cout << element << " ";
        }
        std::cout << "]\n";
    }

    void permuteRecursive(std::vector<int>& nums, std::vector<int> currPermutation,
    std::unordered_set<int> seen, std::vector<std::vector<int>>& res)
    {
        if (currPermutation.size() == nums.size())
        {
            res.push_back(currPermutation);
            return;
            // printVector(currPermutation);
        }

        for (const int num : nums)
        {
            if (!seen.count(num))
            {
                std::vector<int> next = currPermutation;
                next.push_back(num);

                auto nextSeen = seen;
                nextSeen.insert(num);

                permuteRecursive(nums, next, nextSeen, res);
            }
        } 
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> res;
        permuteRecursive(nums, {}, {}, res);
        return res;
    }
};

/*
void permuteRecursive(vector& nums, vector currPermutation, set seen (passed by value)):

   print currPermutation

    for num in nums
        if num not in seen
            permuteRecursive(nums, currPemutation + num, seen + num)

*/


/*

2^n


[ [1, 2], [2, 1] ]


[1]

[[1]] only one permutation

[1, 2, 3]

[ [1, 2, 3], [2, 1, 3] ]

needs recursion

*/


