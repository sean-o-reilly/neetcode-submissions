class Solution {
public:

    void recurse(vector<vector<int>>& res, const vector<int>& nums, vector<int> subset,
        int currIdx, bool choose)
    {
        if (currIdx >= nums.size())
        {
            return; // out of bounds, finished
        }

        if (choose)
        {
            subset.push_back(nums.at(currIdx));
            res.push_back(subset);
        }

        currIdx += 1;
        recurse(res, nums, subset, currIdx, true);
        recurse(res, nums, subset, currIdx, false);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res{{}};
        recurse(res, nums, {}, 0, true);
        recurse(res, nums, {}, 0, false);
        return res;
    }
};


/*
Recursion
choose to add or not to add for each index
[] -> chose no on all numbers
[1] -> only chose 1
[2] ..
[3] ..
[1, 2] -> only chose 1 and 2
[1, 3] -> chose 1, skipped 2, chose 3
...

[1, 2, 3] -> chose all


[1, 2]

recursive function,
    branching in two paths

global result array

recur (array, subset, currIdx, choose)
    if currIdx out of bounds, do nothing

    else

    if choose == true
        globalArray.add (subset + array[currIdx])
    
    currIdx += 1
    recur(array, subset, currIdx, true)
    recur(array, subset, currIdx, false)

globalArray = [[]]
array = [1, 2, 3]
recur (array, [], 0, true)
recur (array, [], 0, false)


*/
