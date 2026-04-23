class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::unordered_set<int> visited;
        for (int i = 0; i <= nums.size(); ++i)
        {
            visited.insert(i);
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            visited.erase(nums[i]);
        }

        return *(visited.begin());
    }
};

/*

[3, 0, 1] 

[0, 2]

*/