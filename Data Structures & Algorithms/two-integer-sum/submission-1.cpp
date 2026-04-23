class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto num = nums.at(i);

            if (seen.contains(target - num))
            {
                return {seen.at(target - num), i};
           }
            seen[num] = i; // else save (num -> idx) pair to seen
        }
    }
};

/*

3, 4, 5, 6

seen
    num -> idx

for each
3 -> 7 - 3 not in seen -> add to seen
4 -> 7 - 4 in seen -> idx of 3, idx of curr, return them

4, 5, 6
t = 10

check for 10 - 4 -> add 4
check for 10 - 5 -> add 5
check for 10 - 6 -> 4 is seen, return 4's mapped val and curr idx

*/
